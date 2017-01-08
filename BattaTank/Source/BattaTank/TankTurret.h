// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, HideCategories(Collision))
class BATTATANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxPerSecondDegree = 50.0f;
public:
	void Rotate(float RelativeDegree);
};
