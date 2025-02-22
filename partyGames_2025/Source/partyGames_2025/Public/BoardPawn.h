// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "BoardPawn.generated.h"

UCLASS()
class PARTYGAMES_2025_API ABoardPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoardPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Function to move the pawn
	void MoveToTarget(int Steps);
	

private:
	bool bIsAdjusting = false; // Prevents infinite loop

	bool bHasAdjusted = false; 
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 300.0f;

	// 🎥 Camera & Spring Arm
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* Camera;

	// Path tracking
	TArray<AActor*> Targets;
	int CurrentTargetIndex = 0;
	int TargetStepCount = 0;
	bool bIsMoving = false;
	bool bHasAdjustedPosition = false;
	// 🟢 Trigger for detecting overlap
	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent* OverlapTrigger;

	// Function to adjust position if overlapping
	void AdjustForOverlap();

	// Function for handling overlap event
	UFUNCTION()
	void OnPawnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
					   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
					   bool bFromSweep, const FHitResult& SweepResult);
	// 🟢 Move pawns aside if needed
	void AdjustBlockingPawn(ABoardPawn* BlockingPawn);
	void CheckAndMoveBlockingPawns(int Steps);
	void SafeMovePawn(ABoardPawn* BlockingPawn, FVector NewLocation);
};


