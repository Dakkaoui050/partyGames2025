// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PawnMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 400.0f;

	// Path tracking
	TArray<AActor*> Targets;
	int CurrentTargetIndex = 0;
	int TargetStepCount = 0;
	bool bIsMoving = false;
};
