// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetVectorHitLocation(FVector& OutHitLocation, FVector HitLocation) const;

	//To tell the tank to aim at the crosshairs
	void AimTowardsCrosshairs();

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33;
	UPROPERTY(EditAnywhere)
		float Range = 1000000.f;
};
