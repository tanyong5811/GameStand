// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "AICrowdFollowingComponent.generated.h"

/**
 * 
 */
UCLASS()
class MCAIR_API UAICrowdFollowingComponent : public UCrowdFollowingComponent
{
	GENERATED_BODY()
public:
	UAICrowdFollowingComponent(const FObjectInitializer& ObjectInitializer);
};
