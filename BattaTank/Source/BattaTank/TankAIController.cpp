// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	ATank* ai = Cast<ATank>(GetPawn());
	ATank* player;
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (playerPawn) {
		player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}

	if (ai) {
		ai->Fire();
	}
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}