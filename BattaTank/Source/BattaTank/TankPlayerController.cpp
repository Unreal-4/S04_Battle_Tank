// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* player = GetTank();
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetTank() const{

	auto pawn = GetPawn();
	if (pawn) {
		return Cast<ATank>(GetPawn());
	}
	else {
		return nullptr;
	}
}

void ATankPlayerController::AimTowardsCrosshair() {
	FVector HitLocation;
	ATank* tank = GetTank();
	if (!tank) { return; }
	if (GetSightRayLocation(HitLocation)) {
		tank->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayLocation(FVector& HitPosition) const{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenPosition = FVector2D(ViewportSizeX * CrossHairLocationX, ViewportSizeY * CrossHairLocationY);
	FVector LookDirection;
	if (GetLookDirection(ScreenPosition, LookDirection)) {
		GetVectorHitLoction(LookDirection, HitPosition);
		return true;
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenPosition, FVector& LookDirection) const {
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenPosition.X, ScreenPosition.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetVectorHitLoction(const FVector& Direction, FVector& LookLocation) const
{
	FHitResult HitResult;
	FVector start = PlayerCameraManager->GetCameraLocation();
	FVector end = start + (Direction * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		start,
		end,
		ECollisionChannel::ECC_Visibility
	)) {
		LookLocation = HitResult.Location;
		return true;
	}
	LookLocation = FVector(0);
	return false;
}
