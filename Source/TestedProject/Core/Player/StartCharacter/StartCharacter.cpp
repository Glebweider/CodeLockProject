// Fill out your copyright notice in the Description page of Project Settings.


#include "StartCharacter.h"

#include "Blueprint/UserWidget.h"


AStartCharacter::AStartCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AStartCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto PC = GetWorld()->GetFirstPlayerController();
	if (StartMenuWidget && PC)
	{
		auto Widget = CreateWidget(PC, StartMenuWidget);
		if (Widget)
		{
			Widget->AddToViewport();
		}

		PC->SetShowMouseCursor(true);
	}
}
