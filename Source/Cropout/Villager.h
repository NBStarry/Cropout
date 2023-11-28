// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "Villager.generated.h"

UCLASS()
class CROPOUT_API AVillager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AVillager();
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCapsuleComponent *Capsule;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent *SkeletalMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent *Tool;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent *Hat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent *Hair;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDecalComponent *Decal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UFloatingPawnMovement *FloatingPawnMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource")
	int Quantity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Job Profile")
	FName NewJob;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Job Profile")
	FName OldJob;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FDateTime CurrentTime;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString GameLogPath = FPaths::ProjectDir() + TEXT("Cropout.txt");

	void InitializeVillager() const;

public:	
	UFUNCTION(BlueprintCallable, Category = "Villager")
	static FString GenerateRandomName();
	UFUNCTION(BlueprintCallable)
	void StopJob();
	UFUNCTION(BlueprintCallable)
	static void WriteInfoToFile(FString Path, FString Info);
	UFUNCTION(BlueprintCallable)
	void LogStartJob();

};
