// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeLock.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TestedProject/UI/Widgets/CodeLock/CodeLockWidget.h"


ACodeLock::ACodeLock()
{
	PrimaryActorTick.bCanEverTick = false;
	
	DoorPassword = TEXT("1234");
}

void ACodeLock::Interact_Implementation(AActor* CharacterInteract)
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	
	if (PC && CodeLockWidget && CharacterInteract)
	{
		if (Widget)
		{
			if (Widget->IsVisible())
			{
				Widget->SetVisibility(ESlateVisibility::Collapsed);
			} else
			{
				Widget->SetVisibility(ESlateVisibility::Visible);
			}
		} else
		{
			auto NewWidget = CreateWidget<UUserWidget>(PC, CodeLockWidget);
			if (NewWidget)
			{
				NewWidget->AddToViewport();
				
				Widget = Cast<UCodeLockWidget>(NewWidget);
				if (Widget)
				{
					Widget->CodeLockOwner = this;
				}
			}
		}
		
		SetVisibilityWidget(Widget->IsVisible());
	}
}

bool ACodeLock::CheckPassword(FString& Input)
{
	if (DoorActor && DoorActor->Implements<UToBuildInterface>())
	{
		if (Input == DoorPassword)
		{
			UGameplayStatics::PlaySound2D(this, VerifySound);
			
			IToBuildInterface::Execute_OpenDoor(DoorActor);
			
			SetVisibilityWidget(false);
			Widget->SetVisibility(ESlateVisibility::Collapsed);
			return true;
		} else if (NotVerifySound)
		{
			UGameplayStatics::PlaySound2D(this, NotVerifySound);
		}		
	}
	return false;
}

void ACodeLock::SetVisibilityWidget(bool bIsVisibility)
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	
	if (Widget && PC)
	{
		PC->bShowMouseCursor = bIsVisibility;
		PC->SetIgnoreMoveInput(bIsVisibility);
		PC->SetIgnoreLookInput(bIsVisibility);
	}
}
