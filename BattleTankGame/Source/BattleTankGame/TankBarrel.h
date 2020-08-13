// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void ElevateBarrel(float ElevateSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5; 
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0; 
};
