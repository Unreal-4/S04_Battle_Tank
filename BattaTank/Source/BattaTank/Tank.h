// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTATANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	void AimAt(FVector);

	UFUNCTION(BluePrintCallable, Category=Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BluePrintCallable, Category=Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BluePrintCallable, Category=Action)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(EditAnywhere, Category=Firing)
	float FiringSpeed = 1000.0f;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent*) override;	
	
};
