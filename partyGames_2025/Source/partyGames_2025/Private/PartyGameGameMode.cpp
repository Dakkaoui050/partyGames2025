// Fill out your copyright notice in the Description page of Project Settings.


#include "PartyGameGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "BoardPawn.h"

void APartyGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> PlayerActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABoardPawn::StaticClass(), PlayerActors);

	TurnManager = Cast<ATurnManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ATurnManager::StaticClass()));
	if (TurnManager && PlayerActors.Num() > 0)
	{
		TurnManager->InitializePlayers(PlayerActors);
	}
}
