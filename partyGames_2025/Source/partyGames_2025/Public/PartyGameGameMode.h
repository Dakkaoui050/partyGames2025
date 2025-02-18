// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TurnManager.h"
#include "PartyGameGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PARTYGAMES_2025_API APartyGameGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	ATurnManager* TurnManager;
};
