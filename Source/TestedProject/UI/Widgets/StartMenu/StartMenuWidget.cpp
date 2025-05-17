// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMenuWidget.h"

#include "Kismet/GameplayStatics.h"

void UStartMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button_Start)
		Button_Start->OnClicked.AddDynamic(this, &UStartMenuWidget::HandleStart);
		
	if (Button_Exit)
		Button_Exit->OnClicked.AddDynamic(this, &UStartMenuWidget::HandleExit);
}

void UStartMenuWidget::HandleStart()
{
	RemoveFromParent();
	
	UGameplayStatics::OpenLevel(this, FName("FirstPersonMap"));
}

void UStartMenuWidget::HandleExit()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
