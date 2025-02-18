// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnManager.h"

// Sets default values
ATurnManager::ATurnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CurrentTurnIndex = 0;
}

// Called when the game starts or when spawned
void ATurnManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ATurnManager::InitializePlayers(TArray<AActor*> Players)
{
	PlayerList = Players;
	CurrentTurnIndex = 0;
}

void ATurnManager::NextTurn()
{
	if (PlayerList.Num() == 0) return;

	CurrentTurnIndex = (CurrentTurnIndex + 1) % PlayerList.Num();
	UE_LOG(LogTemp, Warning, TEXT("Player %d's turn!"), CurrentTurnIndex);
}

AActor* ATurnManager::GetCurrentPlayer()
{
	if (PlayerList.IsValidIndex(CurrentTurnIndex))
	{
		return PlayerList[CurrentTurnIndex];
	}
	return nullptr;
}

