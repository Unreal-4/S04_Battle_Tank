// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "Projectile.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	ProjectilesMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectiles Movement Component"));
	ProjectilesMovementComponent->bAutoActivate = false;
}

void AProjectile::LaunchProjectile(float LaunchSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("Launching projectile at speed %f."), LaunchSpeed);
	ProjectilesMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	ProjectilesMovementComponent->Activate();
}

