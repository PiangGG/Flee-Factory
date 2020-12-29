// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FFPlayerController.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPlayerControllerState:uint8
{
	ENomer		UMETA(DisplayName="正常"),
};

UENUM(BlueprintType)
enum class EPlayInputState:uint8
{
	EOnlyGame	UMETA(DisplayName="仅游戏"),
	EOnlyUI		UMETA(DisplayName="仅UI"),
	EGameAndUI	UMETA(DisplayName="游戏中显示UI"),
};
UCLASS()
class FLEEFACTORY_API AFFPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
	AFFPlayerController();

	//玩家UI数组
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="PlayerUI")
	TArray<UUserWidget*> UserWidgets;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="PlayerUI")
	TSubclassOf<UUserWidget> CurrentUserWidget;
	/*UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="PlayerUI")
	UUserWidget* CurrentUserWidget;
	
	UFUNCTION(BlueprintCallable,Category="PlayerUI")
	UUserWidget *GetCurrentPlayerUserWidget();
	
	UFUNCTION(BlueprintCallable)
	void ChangeUserWidget(UUserWidget* newUserWidgets);

	UFUNCTION(BlueprintCallable)
	void HideAllWidgets();*/
};
