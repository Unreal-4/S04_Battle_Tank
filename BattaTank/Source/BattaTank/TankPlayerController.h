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
	
private:
	void BeginPlay() override;
	void Tick(float) override;
	ATank* GetTank();
	void AimTowardsCrosshair();
	bool GetSightRayLocation(FVector2D&);
	
};
