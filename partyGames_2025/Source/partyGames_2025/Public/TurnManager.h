// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurnManager.generated.h"

UCLASS()
class PARTYGAMES_2025_API ATurnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void InitializePlayers(TArray<AActor*> Players); 
	void NextTurn();
	AActor* GetCurrentPlayer();
	void FinishTurnSwitch();
	void CheckIfP1FinishedMoving();
	FTimerHandle CheckMovementTimer; // ✅ Track the timer globally

private:
	TArray<AActor*> PlayerList;
	int CurrentTurnIndex;
};
