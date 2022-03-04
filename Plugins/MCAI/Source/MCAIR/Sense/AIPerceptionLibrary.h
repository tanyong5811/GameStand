// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AIPerceptionLibrary.generated.h"

/**
 *
 */
UCLASS()
class MCAIR_API UAIPerceptionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "AIPerception")
		static void SetSightConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float SightRadius, float LoseSightRadius, float SightDegrees);

	UFUNCTION(BlueprintCallable, Category = "AIPerception")
		static void SetHearConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float HearRange);

	UFUNCTION(BlueprintPure, Category = "AIPerception")
		static void GetSightConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float& SightRadius, float& LoseSightRadius, float& SightDegrees);

	UFUNCTION(BlueprintPure, Category = "AIPerception")
		static void GetHearConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float& HearRange);
};
