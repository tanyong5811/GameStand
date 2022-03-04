// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AICrowdController.generated.h"

/**
 *
 */
UCLASS()
class MCAIR_API AAICrowdController : public AAIController
{
	GENERATED_BODY()
public:
	AAICrowdController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
