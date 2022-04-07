// Copyright Epic Games, Inc. All Rights Reserved.

#include "Final_1GameMode.h"
#include "Final_1HUD.h"
#include "Final_1Character.h"
#include "UObject/ConstructorHelpers.h"

AFinal_1GameMode::AFinal_1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFinal_1HUD::StaticClass();
}
