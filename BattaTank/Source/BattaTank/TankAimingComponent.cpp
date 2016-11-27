// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float FiringSpeed) {
	FVector OutLaunchDirection;
	if (
		UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchDirection,
			Barrel->GetSocketLocation(FName("FireStart")),
			HitLocation,
			FiringSpeed,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
		) {
		OutLaunchDirection = OutLaunchDirection.GetSafeNormal();
		AimTowards(OutLaunchDirection);
	}	
}


void UTankAimingComponent::AimTowards(FVector AimDirection) {
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(5);
}
