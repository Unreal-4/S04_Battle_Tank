// Fill out your copyright notice in the Description page of Project Settings.

#include "BattaTank.h"
#include "TankPlayerController.h"




ATank* ATankPlayerController::getTank() {

	return (ATank*)GetPawn();
}