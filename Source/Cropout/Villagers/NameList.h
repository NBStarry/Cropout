#pragma once

#include "CoreMinimal.h"
#include "NameList.generated.h"

USTRUCT(BlueprintType)
struct CROPOUT_API FNameList : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FirstName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LastName;
	
};
