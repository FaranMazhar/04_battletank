// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshairs();
}

//Line trace to see through the crosshairs, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	///Finding the cursor position on screen.
	int32 ViewportXSize, ViewportYSize;
	GetViewportSize(ViewportXSize, ViewportYSize);
	auto ScreenLocation = FVector2D(ViewportXSize * CrosshairXLocation, ViewportYSize * CrosshairYLocation);

	/// De-project screen position to world.
	FVector CameraWorldLocataion, HitDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocataion, HitDirection))
	{
		return GetVectorHitLocation(OutHitLocation, HitDirection);
	}
	return false;
}

bool ATankPlayerController::GetVectorHitLocation(FVector& OutHitLocation, FVector LookDirection) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * Range);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Camera
	))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	return false;
}

void ATankPlayerController::AimTowardsCrosshairs()
{
	if (!GetPawn()) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		AimingComponent->AimAt(HitLocation);
	}
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PlayerTank = Cast<ATank>(InPawn);
		if (!ensure(PlayerTank)) { return; }
		PlayerTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPlayerTankDeath);
	}
}

void ATankPlayerController::OnPlayerTankDeath()
{
	StartSpectatingOnly();
}
