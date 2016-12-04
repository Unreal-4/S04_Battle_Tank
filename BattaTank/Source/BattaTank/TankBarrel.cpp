// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float RelativeDegree) {
	SetRelativeRotation(
		FRotator(
			FMath::Clamp<float>(
				RelativeRotation.Pitch + FMath::Clamp<float>(RelativeDegree, -1, 1) * MaxPerSecondDegree * GetWorld()->GetDeltaSeconds(),
				MinElevationDegree,
				MaxElevationDegree
			),
			0,
			0
		)
	);
}
