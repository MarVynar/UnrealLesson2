// Copyright Epic Games, Inc. All Rights Reserved.

#include "RadioLessonGameMode.h"
#include "RadioLessonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARadioLessonGameMode::ARadioLessonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
