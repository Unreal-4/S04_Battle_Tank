// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* player = getTank();
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("Tank Player Controller begin play %s"), *player->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Got null player tank."));
	}
	
}

ATank* ATankPlayerController::getTank() {

	return Cast<ATank>(GetPawn());
}