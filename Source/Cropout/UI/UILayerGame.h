// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Interactable/Resources.h"
#include "UILayerGame.generated.h"

/**
 * 
 */

UCLASS()
class CROPOUT_API UUILayerGame : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox *ResourceContainer;
	UPROPERTY(BlueprintReadWrite)
	EResourceType Resources = EResourceType::Food;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock *NameText;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock *WorkText;

public:
	// virtual void NativeOnInitialized() override;
	// virtual void NativePreConstruct() override;
	UFUNCTION()
	void SetVillagerInfo(const FText &NewName, const FText &NewWork);

protected:
	UFUNCTION(BlueprintCallable)
	void AddResource();
	UFUNCTION()
	void ClearChildrenAndMore();
	
};
