#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICharacterBase.generated.h"

UCLASS(BlueprintType)
class MCAIR_API AAICharacterBase : public ACharacter
{
	GENERATED_BODY()
public:

	void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override;

	UFUNCTION(BlueprintImplementableEvent, Category = "AICharacter")
		FRotator	GetAIEyesRotation() const ;

};