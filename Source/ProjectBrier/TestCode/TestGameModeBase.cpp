// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameModeBase.h"

#include "TestPawn.h"


ATestGameModeBase::ATestGameModeBase()
	: AGameModeBase()
{
	DefaultPawnClass = ATestPawn::StaticClass();
}