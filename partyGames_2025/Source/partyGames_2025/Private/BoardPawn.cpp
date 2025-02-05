// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardPawn.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABoardPawn::ABoardPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PawnMesh"));
	RootComponent = PawnMesh;
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
		FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);

		SetActorLocation(NewLocation);

		// Check if close to target
		if (FVector::Dist(NewLocation, TargetLocation) < 10.0f)
		{
			CurrentTargetIndex++;
			TargetStepCount--;

			if (TargetStepCount <= 0)
			{
				bIsMoving = false; // Stop movement
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
		TargetStepCount = Steps;
		bIsMoving = true;
	}
}

