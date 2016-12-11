// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float RelativeDegree) {
	SetRelativeRotation(FRotator(0,
		RelativeRotation.Yaw + FMath::Clamp<float>(RelativeDegree, -1, 1) * MaxPerSecondDegree * GetWorld()->GetDeltaSeconds(),
		0)
	);
}
