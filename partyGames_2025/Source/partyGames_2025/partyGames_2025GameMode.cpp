// Copyright Epic Games, Inc. All Rights Reserved.

#include "partyGames_2025GameMode.h"
#include "partyGames_2025Character.h"
#include "UObject/ConstructorHelpers.h"

ApartyGames_2025GameMode::ApartyGames_2025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
