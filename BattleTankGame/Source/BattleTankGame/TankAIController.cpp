// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	auto PlayerTank = GetPlayerTank();   
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank: %s"), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank controlled by AI"));
	}
}

ATank* ATankAIController::GetPossessedTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	else
	{
		return Cast<ATank>(PlayerTank);
	}
}
