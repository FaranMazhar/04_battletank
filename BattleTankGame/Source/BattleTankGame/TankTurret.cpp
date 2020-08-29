// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::RotateTurret(float RotationSpeed)
{
	RotationSpeed = FMath::Clamp<float>(RotationSpeed, -1, 1);
	auto RotationChange = RotationSpeed * MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto Rotation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}
