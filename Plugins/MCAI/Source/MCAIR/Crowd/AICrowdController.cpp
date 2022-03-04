// Fill out your copyright notice in the Description page of Project Settings.


#include "AICrowdController.h"
#include "AICrowdFollowingComponent.h"

AAICrowdController::AAICrowdController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UAICrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{

}