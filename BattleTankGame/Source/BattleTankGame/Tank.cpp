// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
<<<<<<< HEAD
=======
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
>>>>>>> master
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
<<<<<<< HEAD
=======
<<<<<<< HEAD

=======
	UE_LOG(LogTemp, Warning, TEXT("SXYTHE: Constructor called.\n"))
>>>>>>> master
}

void ATank::BeginPlay()
{
	Super::BeginPlay();  //Needed for BP begin play to work.
<<<<<<< HEAD
=======
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
>>>>>>> dedce7ecf395fccabb5ed7a7080b58bbaf5c6fd1
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
>>>>>>> master
}

void ATank::Fire()
{
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime > ReloadTime);
	if (Barrel && bIsReloaded)
	{
		//Spawn a projectile at socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

}
