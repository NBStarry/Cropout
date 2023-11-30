// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CROPOUT_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// UMainGameInstance();
	virtual void Init() override;

public:
	UPROPERTY()
	UDataTable *NameTable;
	
};
