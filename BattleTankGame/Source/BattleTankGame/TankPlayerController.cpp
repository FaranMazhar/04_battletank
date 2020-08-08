// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	auto Tank = GetControlledTank();
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank: %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank possessed by controller"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshairs();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

//Line trace to see through the crosshairs, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	///Finding the cursor position on screen.
	int32 ViewportXSize, ViewportYSize;
	GetViewportSize(ViewportXSize, ViewportYSize);
	auto ScreenLocation = FVector2D(ViewportXSize * CrosshairXLocation, ViewportYSize * CrosshairYLocation);

	/// De-project screen position to world.
	FVector CameraWorldLocataion, WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocataion, WorldDirection))
	{
		//GetVectorHitLocation();
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *WorldDirection.ToString())
	}

	///Line trsce to see what we hit
	return true;
}

bool ATankPlayerController::GetVectorHitLocation(FVector& OutHitLocation) const
{
	//TODO GetWorld()->LineTraceSingleByChannel();
	return false;
}

void ATankPlayerController::AimTowardsCrosshairs()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
	}
	
	//TODO tell the tank to aim towards the crosshairs.
}
