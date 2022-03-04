#include "AICharacterBase.h"

void AAICharacterBase::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	Location = GetPawnViewLocation();
	Rotation = GetAIEyesRotation();
}

