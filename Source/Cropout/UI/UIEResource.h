// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interactable/Resources.h"
#include "UIEResource.generated.h"

/**
 * 
 */
UCLASS()
class CROPOUT_API UUIEResource : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	EResourceType ResourceType1;

public:
// 	virtual void NativePreConstruct() override;
	// virtual void NativeConstruct() override;
// 	virtual void NativeOnInitialized() override;
};
