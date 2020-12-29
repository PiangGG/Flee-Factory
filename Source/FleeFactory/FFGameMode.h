// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FFGameMode.generated.h"

/**
 *@anchor piang
 * 控制游戏状态，角色生成，地图状态，地图生成
 */

//枚举游戏状体
UENUM()
enum class EGameState:uint8
{
	EInMainMenu UMETA(DisplayName="主界面"),
	EInGameing  UMETA(DisplayName="游戏中"),
	EInGameOver UMETA(DisplayName="游戏结束")
};
UCLASS()
class FLEEFACTORY_API AFFGameMode : public AGameMode
{
	GENERATED_BODY()
public:
	AFFGameMode();
	
	UFUNCTION(BlueprintCallable)
	void StartGame();
	
	void OverGame();

	UFUNCTION(BlueprintCallable)
	EGameState GetGameState();
	UFUNCTION(BlueprintCallable)
	void ChangeGameState(EGameState NewGameState);
	UFUNCTION(BlueprintCallable)
	void SetGameState(EGameState NewGameState);
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly)
	EGameState CurrentGameState;
};
