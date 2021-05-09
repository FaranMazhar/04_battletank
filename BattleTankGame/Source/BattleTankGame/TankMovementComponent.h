// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;

/**
 * Tank Movement Component sets the movement methods for the player tank and the AI Tanks. 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTracks* RightTrackToSet, UTankTracks* LeftTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnRight(float Throw);

	
	
private:
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankTracks* RightTrack = nullptr;
	UTankTracks* LeftTrack = nullptr;
};
