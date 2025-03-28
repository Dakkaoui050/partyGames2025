// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
//#include "Components/BoxComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABoardPawn::ABoardPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	RootComponent = PawnMesh;

	// 🎥 Create the Spring Arm (keeps the camera behind the pawn)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(PawnMesh);
	SpringArm->TargetArmLength = 300.0f; // Distance from pawn
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;
	SpringArm->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f)); // Look slightly down

	// 🎥 Create the Camera Component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	// 🟢 Create the trigger box for detecting overlap
	//OverlapTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapTrigger"));
	//OverlapTrigger->SetupAttachment(RootComponent);
	//OverlapTrigger->SetBoxExtent(FVector(50.0f, 50.0f, 100.0f));
	//OverlapTrigger->SetCollisionProfileName(TEXT("Trigger"));

	// Bind the overlap event
	//OverlapTrigger->OnComponentBeginOverlap.AddDynamic(this, &ABoardPawn::OnPawnOverlap);
}

// Called when the game starts or when spawned
void ABoardPawn::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundTargets;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName("BoardTarget"), FoundTargets);
    
	if (FoundTargets.Num() > 0)
	{
		Targets = FoundTargets;
		Targets.Sort([](const AActor& A, const AActor& B) {
			return A.GetActorLocation().X < B.GetActorLocation().X; // Sort by position
		});
	}
}

// Called every frame
void ABoardPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	if (bIsMoving && Targets.IsValidIndex(CurrentTargetIndex))
	{
		FVector TargetLocation = Targets[CurrentTargetIndex]->GetActorLocation();
		FVector CurrentLocation = GetActorLocation();

		// Adjust the speed for smoother movement
		float InterpSpeed = MoveSpeed;  

		// Move smoothly towards the target
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, InterpSpeed);
		SetActorLocation(NewLocation);

		// Check if the pawn has reached its current target
		if (FVector::Dist(NewLocation, TargetLocation) < 5.0f) // Threshold for stopping at a step
		{
			TargetStepCount--;

			if (TargetStepCount > 0)
			{
				CurrentTargetIndex++; // Move to the next step
			}
			else
			{
				
				bIsMoving = false; // Stop movement when steps are finished
			}
		}
	}
}


// Called to bind functionality to input
void ABoardPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ABoardPawn::MoveToTarget(int Steps)
{
	if (!bIsMoving && Targets.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is about to move %d steps."), *GetName(), Steps);

		// 🟢 Step 1: Check and move any pawns in the path
		CheckAndMoveBlockingPawns(Steps);

		// 🟢 Step 2: Now start the actual movement
		TargetStepCount = Steps;
		bIsMoving = true;
	}
}
void ABoardPawn::AdjustForOverlap()
{
	if (!OverlapTrigger) return;

	TArray<AActor*> OverlappingActors;
	OverlapTrigger->GetOverlappingActors(OverlappingActors, ABoardPawn::StaticClass());

	if (OverlappingActors.Num() <= 1) return; // No need to adjust if only one pawn

	FVector CenterLocation = GetActorLocation();  
	float OffsetAmount = 50.0f; 
	int TotalPawns = OverlappingActors.Num();
	int Index = 0;

	UE_LOG(LogTemp, Warning, TEXT("Adjusting %d overlapping pawns"), TotalPawns);

	for (AActor* Actor : OverlappingActors)
	{
		ABoardPawn* OtherPawn = Cast<ABoardPawn>(Actor);
		if (OtherPawn)
		{
			// Spread pawns in a circular pattern
			float Angle = (360.0f / TotalPawns) * Index;
			float XOffset = OffsetAmount * FMath::Cos(FMath::DegreesToRadians(Angle));
			float YOffset = OffsetAmount * FMath::Sin(FMath::DegreesToRadians(Angle));

			FVector NewLocation = CenterLocation + FVector(XOffset, YOffset, 0);
			OtherPawn->SetActorLocation(NewLocation);
			Index++;
		}
	}

	// ✅ Reset flag to allow future adjustments
	bHasAdjustedPosition = false;
}

void ABoardPawn::OnPawnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
							   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
							   bool bFromSweep, const FHitResult& SweepResult)
{
	ABoardPawn* OtherPawn = Cast<ABoardPawn>(OtherActor);
	if (OtherPawn && OtherPawn != this)
	{
		// Only adjust if not already adjusting
		if (!bHasAdjustedPosition)
		{
			bHasAdjustedPosition = true;

			// Delay the adjustment slightly to prevent recursion
			FTimerHandle TimerHandle;
			GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoardPawn::AdjustForOverlap, 0.1f, false);
		}
	}
}

void ABoardPawn::AdjustBlockingPawn(ABoardPawn* BlockingPawn)
{
	if (!BlockingPawn || BlockingPawn->bIsAdjusting) return; // Prevent multiple adjustments

	BlockingPawn->bIsAdjusting = true; // Mark as adjusting

	FVector CenterLocation = BlockingPawn->GetActorLocation();

	// 🟢 Get all pawns at the same spot
	TArray<AActor*> OverlappingPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardPawn::StaticClass(), OverlappingPawns);

	TArray<ABoardPawn*> PawnsAtSameSpot;
	for (AActor* Actor : OverlappingPawns)
	{
		ABoardPawn* OtherPawn = Cast<ABoardPawn>(Actor);
		if (OtherPawn && FVector::Dist(CenterLocation, OtherPawn->GetActorLocation()) < 50.0f)
		{
			PawnsAtSameSpot.Add(OtherPawn);
		}
	}

	// 🟢 Spread pawns only if multiple exist in the same spot
	int TotalPawns = PawnsAtSameSpot.Num();
	if (TotalPawns > 1)
	{
		float Radius = 1000.0f; // Spread distance

		for (int i = 0; i < TotalPawns; i++)
		{
			FVector NewLocation = CenterLocation;

			if (i == 0)
			{
				// 🟢 First pawn moves to the left
				NewLocation.X -= Radius;
			}
			else
			{
				// 🟢 Others spread in a circle
				float Angle = (360.0f / (TotalPawns - 1)) * (i - 1);
				float XOffset = Radius * FMath::Cos(FMath::DegreesToRadians(Angle));
				float YOffset = Radius * FMath::Sin(FMath::DegreesToRadians(Angle));

				NewLocation = CenterLocation + FVector(XOffset, YOffset, 0);
			}

			// 🟢 Move the pawn safely
			SafeMovePawn(PawnsAtSameSpot[i], NewLocation);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Adjusted %d pawns safely (first left, then circular)"), TotalPawns);
}


void ABoardPawn::CheckAndMoveBlockingPawns(int Steps)
{
	// 🟢 Loop through each step in the movement path
	for (int i = 0; i < Steps; i++)
	{
		int CheckIndex = CurrentTargetIndex + i;

		// Make sure the index is valid
		if (Targets.IsValidIndex(CheckIndex))
		{
			FVector CheckLocation = Targets[CheckIndex]->GetActorLocation();

			// Find if any pawn is at that location
			TArray<AActor*> FoundPawns;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardPawn::StaticClass(), FoundPawns);

			for (AActor* Actor : FoundPawns)
			{
				ABoardPawn* OtherPawn = Cast<ABoardPawn>(Actor);
				if (OtherPawn && OtherPawn != this)
				{
					// If the pawn is exactly at the target location, move it aside
					if (FVector::Dist(OtherPawn->GetActorLocation(), CheckLocation) < 10.0f)
					{
						AdjustBlockingPawn(OtherPawn);
					}
				}
			}
		}
	}
}

void ABoardPawn::SafeMovePawn(ABoardPawn* BlockingPawn, FVector NewLocation)
{
	if (!BlockingPawn) return;

	// ✅ Use the class member instead of creating a local variable
	GetWorldTimerManager().SetTimer(MoveTimer, [BlockingPawn, NewLocation]()
	{
		if (BlockingPawn) 
		{
			BlockingPawn->SetActorLocation(NewLocation);
			BlockingPawn->bIsAdjusting = false;
		}
	}, 0.1f, false);
}


void ABoardPawn::UpdateSmoothMovement()
{
	if (!bIsMovingAside) return;

	// ✅ Log movement progress
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s is moving towards X=%.2f, Y=%.2f, Z=%.2f"), 
		   *GetName(), MoveTargetLocation.X, MoveTargetLocation.Y, MoveTargetLocation.Z);

	// ✅ Ensure movement is safe
	if (!IsValid(this))
	{
		UE_LOG(LogTemp, Error, TEXT("[ERROR] %s is invalid! Cannot move."), *GetName());
		return;
	}

	// ✅ Gradual movement using interpolation
	FVector NewLocation = FMath::VInterpTo(GetActorLocation(), MoveTargetLocation, GetWorld()->GetDeltaSeconds(), 3.0f);
	SetActorLocation(NewLocation);

	// ✅ Stop moving when close enough
	if (FVector::Dist(GetActorLocation(), MoveTargetLocation) < 5.0f)
	{
		bIsMovingAside = false;
		GetWorldTimerManager().ClearTimer(MoveTimer);
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s has finished moving aside."), *GetName());
	}
}

void ABoardPawn::MoveAsideForNextPlayer()
{
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s: MoveAsideForNextPlayer() triggered."), *GetName());

	TArray<AActor*> NearbyPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardPawn::StaticClass(), NearbyPawns);

	FVector CenterLocation = GetActorLocation();
	float OffsetAmount = 150.0f; // Distance to step aside

	for (AActor* Actor : NearbyPawns)
	{
		ABoardPawn* OtherPawn = Cast<ABoardPawn>(Actor);
		if (OtherPawn && OtherPawn != this && FVector::Dist(CenterLocation, OtherPawn->GetActorLocation()) < 50.0f)
		{
			if (!IsValid(OtherPawn))
			{
				UE_LOG(LogTemp, Error, TEXT("[ERROR] Invalid pawn detected. Skipping move."));
				continue;
			}

			// ✅ Move in the correct direction
			FVector FacingDirection = OtherPawn->GetActorForwardVector();
			FacingDirection.Z = 0;

			// ✅ Compute new location
			FVector TargetLocation = CenterLocation + (FacingDirection * -OffsetAmount);

			// ✅ Move and update status
			OtherPawn->bIsMovingAside = true;
			OtherPawn->MoveOverTime(TargetLocation, 0.6f);

			UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s is smoothly moving aside to: X=%.2f, Y=%.2f before next player arrives"), 
				   *OtherPawn->GetName(), TargetLocation.X, TargetLocation.Y);
		}
	}
}


void ABoardPawn::MoveSmoothly(FVector TargetLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s: MoveSmoothly() called. Moving to: X=%.2f, Y=%.2f, Z=%.2f"), 
		   *GetName(), TargetLocation.X, TargetLocation.Y, TargetLocation.Z);

	// Ensure we don't start multiple movement timers
	if (MoveTimer.IsValid())
	{
		GetWorldTimerManager().ClearTimer(MoveTimer);
	}

	MoveTargetLocation = TargetLocation;
	bIsMovingAside = true;

	// Gradually move toward the target location
	GetWorldTimerManager().SetTimer(MoveTimer, this, &ABoardPawn::UpdateSmoothMovement, 0.01f, true);
}


void ABoardPawn::CheckAndMoveBlockingPawns()
{
	FVector TargetLocation = GetActorLocation();

	// Find if any pawn is at that location
	TArray<AActor*> FoundPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardPawn::StaticClass(), FoundPawns);

	for (AActor* Actor : FoundPawns)
	{
		ABoardPawn* OtherPawn = Cast<ABoardPawn>(Actor);
		if (OtherPawn && OtherPawn != this)
		{
			// If another pawn is at the target location, move it aside
			if (FVector::Dist(OtherPawn->GetActorLocation(), TargetLocation) < 150.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Moving blocking pawn %s from location (%.2f, %.2f)"), 
					   *OtherPawn->GetName(), TargetLocation.X, TargetLocation.Y);

				OtherPawn->MoveAsideForNextPlayer();
			}
		}
	}
}
void ABoardPawn::MoveOverTime(FVector TargetLocation, float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s: MoveOverTime() called. Moving to: X=%.2f, Y=%.2f in %.2f seconds"), 
		   *GetName(), TargetLocation.X, TargetLocation.Y, Duration);

	USceneComponent* RootComp = GetRootComponent();
	if (!RootComp) return;

	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;

	// ✅ Move the pawn smoothly over `Duration` seconds
	UKismetSystemLibrary::MoveComponentTo(RootComp, TargetLocation, FRotator::ZeroRotator, false, false, Duration, false, EMoveComponentAction::Move, LatentInfo);

	// ✅ Wait until movement is finished, then mark as done
	FTimerHandle FinishMoveTimer;
	GetWorldTimerManager().SetTimer(FinishMoveTimer, this, &ABoardPawn::FinishMoveAside, Duration, false);
}

// 🟢 Called when the movement finishes
void ABoardPawn::FinishMoveAside()
{
	bIsMovingAside = false;
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s has finished moving aside."), *GetName());
}




