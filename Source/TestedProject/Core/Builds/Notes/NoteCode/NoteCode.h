// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "GameFramework/Actor.h"
#include "TestedProject/Core/Inventory/Components/Interact/Interface/InteractInterface.h"
#include "NoteCode.generated.h"

UCLASS()
class TESTEDPROJECT_API ANoteCode : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	/** Implements */
	virtual void Interact_Implementation(AActor* CharacterInteract) override;

protected:
	/** Widgets */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Widgets")
	TSubclassOf<UUserWidget> NoteCodeWidget;
	
	UPROPERTY()
	UUserWidget* Widget;
};
