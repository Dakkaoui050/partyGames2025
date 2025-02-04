// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h" // Include for UArrowComponent
#include "DiceActor.generated.h"
UCLASS()
class PARTYGAMES_2025_API ADiceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADiceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
 
  // Function to roll the dice
    void RollDice();

	// Function to check which number is on top
	void CheckDiceResult();
private:
    // Static Mesh Component for the Dice
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* DiceMesh;

	// Timer handle for checking when dice stops

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow3;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow4;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow5;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dice", meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Arrow6;
	
	// Helper function to map world rotation to dice number
	FTimerHandle DiceCheckTimer;
	int GetTopFaceNumber();
};
