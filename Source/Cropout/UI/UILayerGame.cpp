// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/UILayerGame.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "UIEResource.h"

// void UUILayerGame::NativeOnInitialized()
// {
// 	Super::NativeOnInitialized();
// 	
// 	ClearChildrenAndMore();
// }
//
// void UUILayerGame::NativePreConstruct()
// {
// 	Super::NativePreConstruct();
// 	
// 	ClearChildrenAndMore();
// }


// void UUILayerGame::AddResource()
// {
// 	const FString ResourcesString = StaticEnum<EResourceType>()->GetValueAsString(Resources);
// 	if (UKismetStringLibrary::EqualEqual_StrStr(ResourcesString, TEXT("E_MAX")) ||
// 		UKismetStringLibrary::EqualEqual_StrStr(ResourcesString, TEXT("E MAX")))
// 	{
// 		UKismetSystemLibrary::K2_PauseTimer(this, TEXT("AddResource"));
// 	}
// 	else
// 	{
// 		UUIEResource *UIEResource = CreateWidget<UUIEResource>(GetWorld()->GetFirstPlayerController());
// 		if (UIEResource)
// 		{
// 			UIEResource->ResourceType1 = Resources;
// 			ResourceContainer->AddChild(UIEResource);
// 		}
// 		Resources = static_cast<EResourceType>(static_cast<uint8>(Resources) + 1);
// 	}
// }
//
// void UUILayerGame::ClearChildrenAndMore()
// {
// 	// ResourceContainer->ClearChildren();
// 	FTimerDynamicDelegate TimerDelegate;
// 	TimerDelegate.BindUFunction(this, FName("AddResource"));
// 	FTimerHandle TimerHandler;
// 	const UWorld *World = GetWorld();
// 	if (World)
// 	{
// 		World->GetTimerManager().SetTimer(TimerHandler, TimerDelegate, 0.1f, true);
// 	}
// 	// World->getgamemode
// 	
// }
//
// void UUILayerGame::SetVillagerInfo(const FText& NewName, const FText& NewWork)
// {
// 	if (NameText)
// 	{
// 		NameText->SetText(NewName);
// 	}
// 	if (WorkText)
// 	{
// 		NameText->SetText(NewWork);
// 	}
// }


