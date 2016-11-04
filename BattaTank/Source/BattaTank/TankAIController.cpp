// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* player = getTank();
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Player Controller begin play %s"), *player->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Got null AI tank."));
	}
}

ATank* ATankAIController::getTank() {

	return Cast<ATank>(GetPawn());
}