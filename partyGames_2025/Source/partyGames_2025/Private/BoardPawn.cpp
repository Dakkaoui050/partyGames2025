// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
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
		UE_LOG(LogTemp, Warning, TEXT("%s is moving %d steps."), *GetName(), Steps);
        
		TargetStepCount = Steps;
		bIsMoving = true;
	}
}



