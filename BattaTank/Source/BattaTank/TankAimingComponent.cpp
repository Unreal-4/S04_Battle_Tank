// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
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
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
		) {
		OutLaunchDirection = OutLaunchDirection.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s from %s at firing speed %f"), *GetOwner()->GetName(), *OutLaunchDirection.ToString(), *Barrel->GetComponentLocation().ToString(), FiringSpeed)
	}	
}
