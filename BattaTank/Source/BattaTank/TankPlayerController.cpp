// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* player = GetTank();
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller begin play %s"), *player->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Got null player tank."));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime) {
	UE_LOG(LogTemp, Warning, TEXT("Ticking in the tank player controller."));
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetTank() {

	auto pawn = GetPawn();
	if (pawn) {
		return Cast<ATank>(GetPawn());
	}
	else {
		return nullptr;
	}
}

void ATankPlayerController::AimTowardsCrosshair() {
	FVector2D HitLocation;
	if (GetSightRayLocation(HitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayLocation(FVector2D& HitLocation) {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	HitLocation = FVector2D(ViewportSizeX * CrossHairLocationX, ViewportSizeY * CrossHairLocationY);
	return true;
}