// Fill out your copyright notice in the Description page of Project Settings.


#include "Villager.h"

#include "AIController.h"
#include "AI/NavigationSystemBase.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Components/DecalComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AVillager::AVillager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Name = GenerateRandomName();
	UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *Name);
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	// static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Meshes/SKM_Villager.SKM_Villager'"));
	// if(SkeletalMeshAsset.Succeeded())
	// {
	// 	SkeletalMeshComponent->SetSkeletalMesh(SkeletalMeshAsset.Object);
	// }
	Tool = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tool"));
	Hat = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hat"));
	Hair = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hair"));
	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingPawnMovement->MaxSpeed = 300.0f;
	FloatingPawnMovement->Acceleration = 4000.0f;
	FloatingPawnMovement->Deceleration = 8000.0f;
	FloatingPawnMovement->TurningBoost = 8.0f;
	
	SetRootComponent(Capsule);
	SkeletalMeshComponent->SetupAttachment(Capsule);
	Decal->SetupAttachment(Capsule);
	Hair->SetupAttachment(SkeletalMeshComponent);
	Tool->SetupAttachment(SkeletalMeshComponent);
	Hat->SetupAttachment(SkeletalMeshComponent);

	Quantity = 0;
	NewJob = TEXT("Idle");
	OldJob = TEXT("Idle");
}

void AVillager::BeginPlay()
{
	Super::BeginPlay();

	InitializeVillager();
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

void AVillager::InitializeVillager() const
{
	Tool->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("hand_rSocket"));
	Hat->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, "headSocket");
}


void AVillager::StopJob()
{
	Tool->SetVisibility(false);
	SkeletalMeshComponent->GetAnimInstance()->Montage_StopGroupByName(0.0f, TEXT("DefaultGroup"));

	if(AAIController *AIController = UAIBlueprintHelperLibrary::GetAIController(this); IsValid(AIController))
	{
		FNavigationSystem::StopMovement(*Cast<AController>(AIController));
	}

	Quantity = 0;

	CurrentTime = FDateTime::Now();
	const FString StopJobMessage = FString::Printf(TEXT("%s: %s has finished %s!\n"), *CurrentTime.ToString(), *Name, *OldJob.ToString());
	// FFileHelper::SaveStringToFile(StopJobMessage, *GameLogPath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
	WriteInfoToFile(GameLogPath, StopJobMessage);
	OldJob = NewJob;
}

void AVillager::WriteInfoToFile(const FString Path, const FString Info)
{
	FFileHelper::SaveStringToFile(Info, *Path, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

void AVillager::LogStartJob()
{
	CurrentTime = FDateTime::Now();
	const FString StartJobMessage = FString::Printf(TEXT("%s: %s begin to %s!\n"), *CurrentTime.ToString(), *Name, *NewJob.ToString());
	WriteInfoToFile(GameLogPath, StartJobMessage);
}
