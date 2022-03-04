// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AISense_Sight_VR_Interface.generated.h"

UINTERFACE(MinimalAPI)
class UAISense_Sight_VR_Interface : public UInterface
{
	GENERATED_BODY()
};

class MCAIR_API IAISense_Sight_VR_Interface
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "AISense_Sight_F_Interface")
		FVector	GetVRLocation_Inline();
};
