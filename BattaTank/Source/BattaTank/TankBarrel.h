// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), HideCategories(Collision))
class BATTATANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxPerSecondDegree = 20.0f;
	UPROPERTY(EditAnywhere, Category=Setup)
		float MaxElevationDegree = 40.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegree = 0.0f;

public:
		void Elevate(float ElevateDegree);
	
	
};
