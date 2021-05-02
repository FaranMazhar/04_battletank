// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 *
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

private:
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetVectorHitLocation(FVector& OutHitLocation, FVector HitLocation) const;

	//To tell the tank to aim at the crosshairs
	void AimTowardsCrosshairs();

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.33;
	UPROPERTY(EditDefaultsOnly)
		float Range = 1000000.f;
};
