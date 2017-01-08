// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTATANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationX = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairLocationY = 0.33333;
	UPROPERTY(EditDefaultsOnly)
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
