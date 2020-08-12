// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"



void UTankBarrel::ElevateBarrel(float DegreesPerSecond)
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Aim Solution Found."), Time);
	//rotate barrel just the right amount with barrel rotation speed. 
}
