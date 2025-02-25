// Fill out your copyright notice in the Description page of Project Settings.


#include "TurnManager.h"
#include "BoardPawn.h"

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

	UE_LOG(LogTemp, Warning, TEXT("TurnManager Initialized with %d players"), PlayerList.Num());

	for (int i = 0; i < PlayerList.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player %d: %s"), i, *PlayerList[i]->GetName());
	}
}


void ATurnManager::NextTurn()
{
	if (PlayerList.Num() == 0) return;

	// 🟢 Get the previous player before switching turns
	AActor* PreviousPlayer = GetCurrentPlayer();
	ABoardPawn* PreviousPawn = Cast<ABoardPawn>(PreviousPlayer);

	if (PreviousPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Moving previous player aside before switching turns: %s"), *PreviousPlayer->GetName());

		// Move P1 aside before the next turn
		PreviousPawn->MoveAsideForNextPlayer();

		// 🟢 Only start the timer if the pawn is valid
		if (GetWorld() && CheckMovementTimer.IsValid())
		{
			GetWorldTimerManager().ClearTimer(CheckMovementTimer);
		}

		GetWorldTimerManager().SetTimer(CheckMovementTimer, this, &ATurnManager::CheckIfP1FinishedMoving, 0.1f, true);

		return; // Prevent immediate turn switch
	}

	// If no previous player, switch turns immediately
	FinishTurnSwitch();
}

// 🟢 Switch turn after delay
void ATurnManager::FinishTurnSwitch()
{
	CurrentTurnIndex = (CurrentTurnIndex + 1) % PlayerList.Num();
	UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Now it's Player %d's turn!"), CurrentTurnIndex);

	// 🟢 Check if the new player’s destination is occupied
	AActor* CurrentPlayer = GetCurrentPlayer();
	ABoardPawn* CurrentPawn = Cast<ABoardPawn>(CurrentPlayer);
	if (CurrentPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] Checking and clearing path for %s"), *CurrentPawn->GetName());
		CurrentPawn->CheckAndMoveBlockingPawns();
	}
}


AActor* ATurnManager::GetCurrentPlayer()
{
	if (PlayerList.IsValidIndex(CurrentTurnIndex))
	{
		UE_LOG(LogTemp, Warning, TEXT("Current player: %s"), *PlayerList[CurrentTurnIndex]->GetName());
		return PlayerList[CurrentTurnIndex];
	}

	UE_LOG(LogTemp, Error, TEXT("CurrentTurnIndex is invalid! Player list size: %d, CurrentTurnIndex: %d"), PlayerList.Num(), CurrentTurnIndex);
	return nullptr;
}
void ATurnManager::CheckIfP1FinishedMoving()
{
	if (!GetWorld()) return; // ✅ Prevents crashes if world is invalid

	AActor* PreviousPlayer = GetCurrentPlayer();

	if (!PreviousPlayer) // ✅ Check if we have a valid previous player
	{
		UE_LOG(LogTemp, Error, TEXT("[ERROR] Previous player is NULL. Stopping movement check."));
		GetWorldTimerManager().ClearTimer(CheckMovementTimer);
		return;
	}

	ABoardPawn* PreviousPawn = Cast<ABoardPawn>(PreviousPlayer);
    
	if (!PreviousPawn) // ✅ Ensure it's a valid BoardPawn
	{
		UE_LOG(LogTemp, Error, TEXT("[ERROR] Previous pawn is NULL. Stopping movement check."));
		GetWorldTimerManager().ClearTimer(CheckMovementTimer);
		return;
	}

	if (!PreviousPawn->bIsMovingAside) // ✅ Check only when movement is done
	{
		UE_LOG(LogTemp, Warning, TEXT("[DEBUG] %s has finished moving. Switching turn..."), *PreviousPlayer->GetName());

		// 🟢 Stop the timer properly
		if (CheckMovementTimer.IsValid())
		{
			GetWorldTimerManager().ClearTimer(CheckMovementTimer);
		}

		// ✅ Now P2 can start moving
		FinishTurnSwitch();
	}
}


