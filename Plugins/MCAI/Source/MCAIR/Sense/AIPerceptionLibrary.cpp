// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPerceptionLibrary.h"
#include "AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "AIModule/Classes/Perception/AISenseConfig.h"
#include "AIModule/Classes/Perception/AISenseConfig_Hearing.h"
#include "AISense_Sight_VR.h"


void UAIPerceptionLibrary::SetSightConfig(UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float SightRadius, float LoseSightRadius, float SightDegrees)
{
	if (perceptionComponent) {
		check(perceptionComponent);
		const UAISenseConfig* config = perceptionComponent->GetSenseConfig(UAISense::GetSenseID(SenseClass));
		const  UAISenseConfig_Sight* SightConfig = Cast<const UAISenseConfig_Sight>(config);
		if (SightConfig) {
			UAISenseConfig_Sight* newSenseConfig = const_cast<UAISenseConfig_Sight*>(SightConfig);
			check(newSenseConfig);
			newSenseConfig->SightRadius = SightRadius;
			newSenseConfig->LoseSightRadius = LoseSightRadius;
			newSenseConfig->PeripheralVisionAngleDegrees = SightDegrees;
			perceptionComponent->ConfigureSense(*newSenseConfig);
			return;
		}
		const  UAISenseConfig_Sight_VR* SightVRConfig = Cast<const UAISenseConfig_Sight_VR>(config);
		if (SightVRConfig) {
			UAISenseConfig_Sight_VR* newSenseConfig = const_cast<UAISenseConfig_Sight_VR*>(SightVRConfig);
			check(newSenseConfig);
			newSenseConfig->SightRadius = SightRadius;
			newSenseConfig->LoseSightRadius = LoseSightRadius;
			newSenseConfig->PeripheralVisionAngleDegrees = SightDegrees;
			perceptionComponent->ConfigureSense(*newSenseConfig);
			return;
		}

	}
}

void UAIPerceptionLibrary::SetHearConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float HearRange)
{
	if (perceptionComponent) {
		check(perceptionComponent);
		const UAISenseConfig* config = perceptionComponent->GetSenseConfig(UAISense::GetSenseID(SenseClass));
		const  UAISenseConfig_Hearing* SenseConfig = Cast<const UAISenseConfig_Hearing>(config);
		UAISenseConfig_Hearing* newSenseConfig = const_cast<UAISenseConfig_Hearing*>(SenseConfig);
		check(newSenseConfig);
		newSenseConfig->HearingRange = HearRange;
		perceptionComponent->ConfigureSense(*newSenseConfig);
	}
}

void UAIPerceptionLibrary::GetSightConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float& SightRadius, float& LoseSightRadius, float& SightDegrees)
{
	if (perceptionComponent) {
		check(perceptionComponent);
		const UAISenseConfig* config = perceptionComponent->GetSenseConfig(UAISense::GetSenseID(SenseClass));
		const  UAISenseConfig_Sight* SightConfig = Cast<const UAISenseConfig_Sight>(config);
		if (SightConfig) {
			SightRadius = SightConfig->SightRadius;
			LoseSightRadius = SightConfig->LoseSightRadius;
			SightDegrees = SightConfig->PeripheralVisionAngleDegrees;
			return;
		}
		const  UAISenseConfig_Sight_VR* SightVRConfig = Cast<const UAISenseConfig_Sight_VR>(config);
		if (SightVRConfig) {
			SightRadius = SightVRConfig->SightRadius;
			LoseSightRadius = SightVRConfig->LoseSightRadius;
			SightDegrees = SightVRConfig->PeripheralVisionAngleDegrees;
			return;
		}

	}
}

void UAIPerceptionLibrary::GetHearConfig(class UAIPerceptionComponent* perceptionComponent, const TSubclassOf<UAISense> SenseClass, float& HearRange)
{
	if (perceptionComponent) {
		check(perceptionComponent);
		const UAISenseConfig* config = perceptionComponent->GetSenseConfig(UAISense::GetSenseID(SenseClass));
		const  UAISenseConfig_Hearing* SenseConfig = Cast<const UAISenseConfig_Hearing>(config);
		HearRange = SenseConfig->HearingRange;
	}
}

