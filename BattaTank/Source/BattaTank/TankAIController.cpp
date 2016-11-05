// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* ai = GetTank();
	if (ai) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Player Controller begin play %s"), *ai->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Got null AI tank."));
	}

	ATank* player = GetPlayer();
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("Get Player in AI begin play %s"), *player->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Failed getting player in AI begin player."));
	}
}

ATank* ATankAIController::GetTank() {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayer() {
	auto playerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (playerPawn) {
		return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
	else {
		return nullptr;
	}
}