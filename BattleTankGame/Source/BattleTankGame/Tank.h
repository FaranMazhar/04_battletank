// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

<<<<<<< HEAD
=======
class UTankAimingComponent;
class UTankMovementComponent;
>>>>>>> master
class AProjectile;
class UTankBarrel;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

<<<<<<< HEAD
=======
protected:
	// Called when the game starts or when spawned
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;


public:
	void AimAt(FVector HitLocation);

>>>>>>> master
	UFUNCTION(BlueprintCallable)
		void Fire();

private:
	//TODO remove once firing method is moved to aiming component.
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000.0;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTime = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Barrel reference
	UTankBarrel* Barrel = nullptr; //TODO Remove

	double LastFireTime = 0;
};
