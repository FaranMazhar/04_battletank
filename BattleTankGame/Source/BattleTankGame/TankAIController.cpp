// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AITank = Cast<ATank>(GetPawn());
	if(PlayerTank)
	{
		AITank->AimAt(PlayerTank->GetActorLocation());
		auto time = GetWorld()->GetRealTimeSeconds();
		AITank->Fire();
	}
}
