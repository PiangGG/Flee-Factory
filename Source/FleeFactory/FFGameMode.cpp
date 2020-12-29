// Fill out your copyright notice in the Description page of Project Settings.


#include "FFGameMode.h"
#include "FFPawn.h"
#include "FFPlayerController.h"

AFFGameMode::AFFGameMode()
{
	DefaultPawnClass = AFFPawn::StaticClass();
	PlayerControllerClass=AFFPlayerController::StaticClass();
}

void AFFGameMode::StartGame()
{
}

void AFFGameMode::OverGame()
{
}

EGameState AFFGameMode::GetGameState()
{
	return CurrentGameState;
}

void AFFGameMode::ChangeGameState(EGameState NewGameState)
{
	
}

void AFFGameMode::SetGameState(EGameState NewGameState)
{
	
}
