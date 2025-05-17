// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StartCharacter.generated.h"

UCLASS()
class TESTEDPROJECT_API AStartCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStartCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character")
	TSubclassOf<UUserWidget> StartMenuWidget;
};
