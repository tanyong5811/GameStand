// Fill out your copyright notice in the Description page of Project Settings.

#include "CrowdComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Navigation/CrowdManager.h"
#include "AIController.h"
#include "Navigation/CrowdAgentInterface.h"
#include "Navigation/CrowdFollowingComponent.h"

// Sets default values for this component's properties
UCrowdComponent::UCrowdComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


UCrowdComponent::~UCrowdComponent()
{
}

// Called when the game starts
void UCrowdComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void UCrowdComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}



void UCrowdComponent::updateCrowdComponent()
{
	AAIController* aiController = Cast<AAIController>(GetOwner()->GetInstigatorController());
	if (aiController) {
		UCrowdFollowingComponent* aiCrowdComponent = Cast<UCrowdFollowingComponent>(aiController->GetPathFollowingComponent());
		if (aiCrowdComponent) {
			ICrowdAgentInterface* AIAgent = Cast<ICrowdAgentInterface>(aiCrowdComponent);

			UCrowdManager* CrowdManager = UCrowdManager::GetCurrent(GetWorld());
			if (CrowdManager)
			{
				CrowdManager->UpdateAgentParams(AIAgent);
			}
		}
	}
}

void UCrowdComponent::initCrowdComponent(const ACharacter* Player, const int32 GroupID)
{
	UCrowdManager* CrowdManager = UCrowdManager::GetCurrent(GetWorld());
	if (!Player) { return; }
	currentMoveMentComponent = Player->GetCharacterMovement();
	if (CrowdManager)
	{
		ICrowdAgentInterface* IAgent = Cast<ICrowdAgentInterface>(this);
		CrowdManager->RegisterAgent(IAgent);
	}
	const TSharedPtr<FNavAvoidanceMask> avoiddanceMask = MakeShared<FNavAvoidanceMask>();
	avoiddanceMask->SetGroup(GroupID);
	currentMoveMentComponent->SetAvoidanceGroupMask(*avoiddanceMask);

}


void UCrowdComponent::EnableCrowd(bool isEnable)
{
	AAIController* aiController = Cast<AAIController>(GetOwner()->GetInstigatorController());
	if (aiController) {
		UCrowdFollowingComponent* aiCrowdComponent = Cast<UCrowdFollowingComponent>(aiController->GetPathFollowingComponent());
		aiCrowdComponent->SuspendCrowdSteering(!isEnable);
	}
}

FVector UCrowdComponent::GetCrowdAgentLocation() const
{
	return 	currentMoveMentComponent ? currentMoveMentComponent->GetActorFeetLocation() : FVector::ZeroVector;
}

FVector UCrowdComponent::GetCrowdAgentVelocity() const
{
	FVector Velocity(currentMoveMentComponent ? currentMoveMentComponent->Velocity : FVector::ZeroVector);
	return Velocity;
}

void UCrowdComponent::GetCrowdAgentCollisions(float& CylinderRadius, float& CylinderHalfHeight) const
{
	if (currentMoveMentComponent && currentMoveMentComponent->UpdatedComponent)
	{
		//FString VeryCleanString = FString::SanitizeFloat(CylinderRadius);
		//CylinderRadius = 500;
		currentMoveMentComponent->UpdatedComponent->CalcBoundingCylinder(CylinderRadius, CylinderHalfHeight);
	}
}

float UCrowdComponent::GetCrowdAgentMaxSpeed() const
{
	return currentMoveMentComponent ? currentMoveMentComponent->GetMaxSpeed() : 0.0f;
}

int32 UCrowdComponent::GetCrowdAgentAvoidanceGroup() const
{
	return currentMoveMentComponent ? currentMoveMentComponent->GetAvoidanceGroupMask() : 0;
}

int32 UCrowdComponent::GetCrowdAgentGroupsToAvoid() const
{
	return currentMoveMentComponent ? currentMoveMentComponent->GetGroupsToAvoidMask() : 0;
}

int32 UCrowdComponent::GetCrowdAgentGroupsToIgnore() const
{
	return currentMoveMentComponent ? currentMoveMentComponent->GetGroupsToIgnoreMask() : 0;
}

