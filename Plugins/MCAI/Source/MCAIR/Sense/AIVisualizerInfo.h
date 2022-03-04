#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AIVisualizerInfo.generated.h"


UCLASS(ClassGroup=AI, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))

class MCAIR_API UAIVisualizerInfo : public USceneComponent {
	GENERATED_BODY()
public:
	UAIVisualizerInfo();
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="AIPawnSense")
		float SightHeight;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="AIPawnSense")
		float NearSightRadius;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="AIPawnSense")
		float FarSightRadius;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="AIPawnSense")
		float SightAngle;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="AIPawnSense")
		float HearThreshold;
	UPROPERTY(EditAnywhere,Category="AIPawnSense")
	FLinearColor NearSightColor;
	UPROPERTY(EditAnywhere,Category="AIPawnSense")
	FLinearColor FarSightColor;
	UPROPERTY(EditAnywhere,Category="AIPawnSense")
	FLinearColor HearColor;

};