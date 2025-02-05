// Fill out your copyright notice in the Description page of Project Settings.


#include "DiceActor.h"
#include "Components/StaticMeshComponent.h"
//#include "GameFramework/PlayerController.h"
#include "BoardPawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "GameFramework/Controller.h"

// Sets default values
ADiceActor::ADiceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach Static Mesh Component
	DiceMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DiceMesh"));
	RootComponent = DiceMesh;

	// Enable physics on the dice
	DiceMesh->SetSimulatePhysics(true);
	DiceMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

	// Add arrows for each face
	Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow1"));
	Arrow1->SetupAttachment(DiceMesh);

	Arrow2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow2"));
	Arrow2->SetupAttachment(DiceMesh);

	Arrow3 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow3"));
	Arrow3->SetupAttachment(DiceMesh);

	Arrow4 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow4"));
	Arrow4->SetupAttachment(DiceMesh);

	Arrow5 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow5"));
	Arrow5->SetupAttachment(DiceMesh);

	Arrow6 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow6"));
	Arrow6->SetupAttachment(DiceMesh);
}

// Called when the game starts or when spawned
void ADiceActor::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		EnableInput(PC);
		InputComponent->BindAction("RollDice", IE_Pressed, this, &ADiceActor::RollDice);
	}
	
}

// Called every frame
void ADiceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADiceActor::RollDice()
{
	if (!DiceMesh) return;

	FVector RandomImpulse = FVector(FMath::RandRange(-300, 300), FMath::RandRange(-300, 300), FMath::RandRange(500, 800));
	FVector RandomTorque = FVector(FMath::RandRange(-50000, 50000), FMath::RandRange(-50000, 50000), FMath::RandRange(-50000, 50000));

	DiceMesh->AddImpulse(RandomImpulse, NAME_None, true);
	DiceMesh->AddTorqueInDegrees(RandomTorque, NAME_None, true);

	GetWorld()->GetTimerManager().SetTimer(DiceCheckTimer, this, &ADiceActor::CheckDiceResult, 1.0f, true);
}

void ADiceActor::CheckDiceResult()
{
	if (!DiceMesh) return;

	FVector Velocity = DiceMesh->GetPhysicsLinearVelocity();
	FVector AngularVelocity = DiceMesh->GetPhysicsAngularVelocityInDegrees();

	if (Velocity.Size() < 1.0f && AngularVelocity.Size() < 1.0f)
	{
		GetWorld()->GetTimerManager().ClearTimer(DiceCheckTimer);

		int DiceNumber = GetTopFaceNumber();
		UE_LOG(LogTemp, Warning, TEXT("Dice landed on: %d"), DiceNumber);

		// Find the Pawn and move it
		ABoardPawn* BoardPawn = Cast<ABoardPawn>(UGameplayStatics::GetActorOfClass(GetWorld(), ABoardPawn::StaticClass()));
		if (BoardPawn)
		{
			BoardPawn->MoveToTarget(DiceNumber);
		}
	}
}

int ADiceActor::GetTopFaceNumber()
{
	if (!DiceMesh) return -1;

	struct FaceCheck
	{
		UArrowComponent* Arrow;
		int FaceNumber;
	};

	// Correctly mapping arrows to face numbers
	FaceCheck Faces[] = {
		{Arrow1, 1},
		{Arrow2, 2},
		{Arrow3, 3},
		{Arrow4, 4},
		{Arrow5, 5},
		{Arrow6, 6}
	};

	UArrowComponent* TopArrow = nullptr;
	float MaxZ = -FLT_MAX; // Smallest possible float value

	for (FaceCheck& Face : Faces)
	{
		if (!Face.Arrow) continue; // Ensure ArrowComponent is valid

		// Get the Arrow's world position
		FVector ArrowWorldPosition = Face.Arrow->GetComponentLocation();

		// Find the arrow with the highest Z-position (pointing upwards)
		if (ArrowWorldPosition.Z > MaxZ)
		{
			MaxZ = ArrowWorldPosition.Z;
			TopArrow = Face.Arrow;
		}
	}

	// Return the face number of the arrow with the highest Z position
	for (FaceCheck& Face : Faces)
	{
		if (Face.Arrow == TopArrow)
		{
			return Face.FaceNumber;
		}
	}

	return -1; // Default case if no arrow is found
}



