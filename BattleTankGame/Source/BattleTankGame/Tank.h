// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;
	

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable)
		void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000.0;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTime = 3;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Barrel reference
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;
};
