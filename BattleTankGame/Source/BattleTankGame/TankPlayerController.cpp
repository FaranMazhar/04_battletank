// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Tank.h"


void ATankPlayerController::BeginPlay()
{
<<<<<<< HEAD
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
=======
	auto Tank = GetControlledTank();
>>>>>>> master
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
		GetVectorHitLocation(OutHitLocation, HitDirection);
	}
	return true;
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
		ECollisionChannel::ECC_Visibility
	))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	return false;
}

void ATankPlayerController::AimTowardsCrosshairs()
{
<<<<<<< HEAD
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

=======
	if (!GetControlledTank()) { return; }
>>>>>>> master
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		AimingComponent->AimAt(HitLocation);
	}
}
