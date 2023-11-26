// Fill out your copyright notice in the Description page of Project Settings.


#include "Villager.h"

// Sets default values
AVillager::AVillager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVillager::BeginPlay()
{
	Super::BeginPlay();

	Name = GenerateRandomName();
	
}

// Called every frame
void AVillager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVillager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Generate a random name for a villager
FString AVillager::GenerateRandomName()
{
	// // TODO: 每次重新开始游戏时重置列表
	// static TArray<FString> NameList = {TEXT("John"), TEXT("Jane"), TEXT("Bob"), TEXT("Alice"), TEXT("Starry")};
	// const int RandomIndex = FMath::RandRange(0, NameList.Num() - 1);
	//
	// FString RandomName = NameList[RandomIndex];
	// NameList.RemoveAt(RandomIndex);
	//
	// return RandomName;

	return TEXT("John");
}
