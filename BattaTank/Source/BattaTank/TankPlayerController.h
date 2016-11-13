// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTATANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float CrossHairLocationX = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairLocationY = 0.33333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0;
	
private:
	void BeginPlay() override;
	void Tick(float) override;
	ATank* GetTank() const;
	void AimTowardsCrosshair();
	bool GetSightRayLocation(FVector&) const;
	bool GetLookDirection(FVector2D, FVector&) const;
	bool GetVectorHitLoction(const FVector&, FVector&) const;
};
