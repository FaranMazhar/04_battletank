// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float DegreesPerSecond)
{
	DegreesPerSecond = FMath::Clamp<float>(DegreesPerSecond, -1, 1);
	auto ElevationChange = DegreesPerSecond * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	//rotate barrel just the right amount with barrel rotation speed. 
}
