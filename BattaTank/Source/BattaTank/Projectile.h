// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTATANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	void LaunchProjectile(float LaunchSpeed);

protected:
	UProjectileMovementComponent* ProjectilesMovementComponent = nullptr;
	
};
