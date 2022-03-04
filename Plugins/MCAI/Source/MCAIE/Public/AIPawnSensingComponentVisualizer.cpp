#include "AIPawnSensingComponentVisualizer.h"
#include "../Sense/AIVisualizerInfo.h"

void FAIPawnSensingComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	if (View->Family->EngineShowFlags.VisualizeSenses)
	{
		const UAIVisualizerInfo* Senses = Cast<const UAIVisualizerInfo>(Component);
		if (Senses != NULL)
		{
			FVector OwnerLocation = Senses->GetComponentLocation();
			FVector SightLocation = FVector(OwnerLocation.X, OwnerLocation.Y, OwnerLocation.Z + Senses->SightHeight);
			const FTransform OwnerTransform = Senses->GetComponentToWorld();
			const FTransform SightTransform = FTransform(Senses->GetComponentRotation(), SightLocation);
			
			//	//LOS hearing
			//	if (Senses->LOSHearingThreshold > 0.0f)
			//	{
			//		DrawWireSphere(PDI, Transform, FColor::Yellow, Senses->LOSHearingThreshold, 16, SDPG_World);
			//	}

				//Hearing
			if (Senses->HearThreshold > 0.0f)
			{
				DrawWireSphere(PDI, OwnerTransform, Senses->HearColor, Senses->HearThreshold, 16, SDPG_World);
				//DrawWireSphere(PDI, OwnerTransform, FColor::Cyan, Senses->HearThreshold, 16, SDPG_World);
			}

			//Near Sight
			if (Senses->NearSightRadius > 0.0f)
			{
				TArray<FVector> Verts;
				DrawWireCone(PDI, Verts, SightTransform, Senses->NearSightRadius, Senses->SightAngle, 8, Senses->NearSightColor, SDPG_World);
			}

			//Far Sight
			if (Senses->FarSightRadius > 0.0f)
			{
				TArray<FVector> Verts;
				DrawWireCone(PDI, Verts, SightTransform, Senses->FarSightRadius, Senses->SightAngle, 10, Senses->FarSightColor, SDPG_World);
			}
		}
	}
}
