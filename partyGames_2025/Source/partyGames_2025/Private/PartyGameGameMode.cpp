// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "BoardPawn.h"

void APartyGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> PlayerActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardPawn::StaticClass(), PlayerActors);

	UE_LOG(LogTemp, Warning, TEXT("Game Mode found %d players"), PlayerActors.Num());

	TurnManager = Cast<ATurnManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ATurnManager::StaticClass()));
	if (TurnManager)
	{
		TurnManager->InitializePlayers(PlayerActors);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TurnManager not found in the scene!"));
	}
}

