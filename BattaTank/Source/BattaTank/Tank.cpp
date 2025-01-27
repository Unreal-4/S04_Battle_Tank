// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Tank.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComp)
{
	Super::SetupPlayerInputComponent(InputComp);

}

void ATank::AimAt(FVector location) {
	TankAimingComponent->AimAt(location, FiringSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	TankBarrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (TankBarrel && FPlatformTime::Seconds() - LastFireTime > ReloadTime) {
		FVector Location = TankBarrel->GetSocketLocation(FName("FireStart"));
		GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			TankBarrel->GetSocketLocation(FName("FireStart")),
			TankBarrel->GetSocketRotation(FName("FireStart"))
			)->LaunchProjectile(FiringSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	
}

