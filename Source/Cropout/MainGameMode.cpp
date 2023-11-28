// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	const FString NewGameMessage = FString::Printf(TEXT("New Game!\n"));
	FFileHelper::SaveStringToFile(NewGameMessage, *GameLogPath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}
