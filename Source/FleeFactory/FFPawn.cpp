// Fill out your copyright notice in the Description page of Project Settings.


#include "FFPawn.h"

#include "FFPlayerController.h"
#include "Components/SphereComponent.h"
// Sets default values
AFFPawn::AFFPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//SphereComponent->SetCollisionEnabled(ECR_Block);
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength=200.f;

	CameraComponent=CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	
	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);
	
	MoveSpeedForce=100;
}

// Called when the game starts or when spawned
void AFFPawn::BeginPlay()
{
	Super::BeginPlay();
	StaticMeshComponent->SetSimulatePhysics(true);
}

// Called every frame
void AFFPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorForwardVector().X!=0)
	{
		//StaticMeshComponent->AddWorldRotation(GetActorRotation(),false);
	}
}

// Called to bind functionality to input
void AFFPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&AFFPawn::MoveForward);
	PlayerInputComponent->BindAction("TheJump",EInputEvent::IE_Pressed,this,&AFFPawn::TheJump);
}

void AFFPawn::MoveForward(float var)
{
	AFFPlayerController *PC=Cast<AFFPlayerController>(GetController());
	if (PC)
	{
		this->AddMovementInput(GetActorForwardVector(),var);
	}
	/*if (var)
	{
		StaticMeshComponent->AddForce(FVector(var*MoveSpeedForce,0,0));
	}*/
}
void AFFPawn::TheJump()
{
	AFFPlayerController *PC=Cast<AFFPlayerController>(GetController());
	if (PC)
	{
		this->Jump();
	}
	
}
