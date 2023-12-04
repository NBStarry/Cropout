// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Resources.generated.h"


/**
 * 
 */
UENUM(BlueprintType)
enum class EResourceType : uint8
{
 None UMETA(DisPlayName = "None"),
 Food UMETA(DisPlayName = "Food"),
 Wood UMETA(DisPlayName = "Wood"),
 Stone UMETA(DisPlayName = "Stone"),
};

UENUM(BlueprintType)
enum class EVillagerHUD : uint8
{
 Name UMETA(DisplayName = "Name"),
 Work UMETA(DisplayName = "Work"),
};
