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
	auto Time = GetWorld()->GetTimeSeconds();
	if (
		UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchDirection,
			Barrel->GetSocketLocation(FName("FireStart")),
			HitLocation,
			FiringSpeed,
			0,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
		) {
		UE_LOG(LogTemp, Warning, TEXT("%f Solution found."), Time)
		OutLaunchDirection = OutLaunchDirection.GetSafeNormal();
		AimTowards(OutLaunchDirection);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%f Solution not found."), Time)
			AimTowards(FVector(0));
	}
}


void UTankAimingComponent::AimTowards(FVector AimDirection) {
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
}
