// Fill out your copyright notice in the Description page of Project Settings.


#include "Villager.h"

#include "AIController.h"
#include "MainGameInstance.h"
#include "AI/NavigationSystemBase.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Components/DecalComponent.h"
#include "NameList.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AVillager::AVillager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
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
FString AVillager::GenerateRandomName() const
{
	// // TODO: 检查重复姓名，重复则重新生成
	FString NewName = TEXT("John");
	if(NameTable != nullptr)
	{
		TArray<FName> RowNames = NameTable->GetRowNames();
		const int RandomIndex1 = FMath::RandRange(0, RowNames.Num() - 1);
		const int RandomIndex2 = FMath::RandRange(0, RowNames.Num() - 1);
		const FName RandomFirstName = RowNames[RandomIndex1];
		const FName RandomLastName = RowNames[RandomIndex2];
		const FString ContextString(TEXT("GENERAL"));

		const FNameList *FirstRow = NameTable->FindRow<FNameList>(RandomFirstName, ContextString);
		const FNameList *LastRow = NameTable->FindRow<FNameList>(RandomLastName, ContextString);
		if(FirstRow != nullptr)
		{
			NewName = FString::Printf(TEXT("%s %s"), *FirstRow->FirstName, *LastRow->LastName);
		}
	}
	return NewName;
}

void AVillager::InitializeVillager()
{
	NameTable = Cast<UMainGameInstance>(GetGameInstance())->NameTable;
	Name = GenerateRandomName();
	UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *Name);
	
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
