// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CROPOUT_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()

	void BeginPlay() override;

protected:
	UPROPERTY()
	FString GameLogPath = FPaths::ProjectDir() + TEXT("Cropout.txt");
};
