// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

UTankTracks::UTankTracks()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTracks::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}

void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurrentThrottle = 0.f;
}

void UTankTracks::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcelleration = -SlippageSpeed * DeltaTime * GetRightVector();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcelleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::SetThrottle(float ThrottleSpeed)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + ThrottleSpeed, -1, 1);
}

void UTankTracks::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
