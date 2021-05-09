// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * TankTracks is used for the throttle settings of the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float ThrottleSpeed);
	//Tank's maximum driving force in newtons.
	UPROPERTY(EditDefaultsOnly, Category = Movement)
		float MaxDrivingForce = 40000000;

private:
	UTankTracks();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void ApplySidewaysForce();
	void DriveTrack();

	float CurrentThrottle = 0;
};
