// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawn.h"

// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	this->PrimaryActorTick.bCanEverTick = true;

	this->AutoPossessPlayer = EAutoReceiveInput::Player0;

	USceneComponent* rootComponent = this->CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	this->SetRootComponent(rootComponent);

	// Dynamic variables
	this->speed = 2.0f;
}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveCharForward", this, &ATestPawn::MoveCharForward);
	PlayerInputComponent->BindAxis("MoveCharStrafe", this, &ATestPawn::MoveCharStrafe);
}

void ATestPawn::MoveCharForward(float axisValue)
{
	FRotator rot(0.0f, this->GetControlRotation().Yaw, 0.0f);

	this->AddActorWorldOffset(rot.Vector() * axisValue);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Axis Value: %s"), *rot.Vector().ToString()));
}

void ATestPawn::MoveCharStrafe(float axisValue)
{
	FRotator rot(0.0f, this->GetControlRotation().Yaw, 0.0f);

	this->AddActorWorldOffset(rot.Vector().RightVector * axisValue);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("Axis Value: %s"), *rot.Vector().ToString()));
}