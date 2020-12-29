// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"

#include "FFPawn.generated.h"

UCLASS()
class FLEEFACTORY_API AFFPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFFPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*Component*/
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	class UCameraComponent*CameraComponent;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	class USpringArmComponent*SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	float MoveSpeedForce;
	/*控制函数*/
	void MoveForward(float var);

	void TheJump();
};


