// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

void UTankTracks::SetThrottle(float ThrottleSpeed)
{
	auto time = GetWorld()->GetRealTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Moving at speed: %f"), time, ThrottleSpeed);
}
