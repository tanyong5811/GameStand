// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Navigation/CrowdAgentInterface.h"



#include "CrowdComponent.generated.h"


class UCharacterMovementComponent;
class UCrowdManager;
class ICrowdAgentInterface;
class ACharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class  UCrowdComponent : public UActorComponent, public ICrowdAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCrowdComponent();
	~UCrowdComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UCharacterMovementComponent * currentMoveMentComponent;

	//怪物实时更新人群数据
	UFUNCTION(BlueprintCallable)
		void updateCrowdComponent();

	//玩家加入人群接口
	UFUNCTION(BlueprintCallable)
		void initCrowdComponent(const ACharacter* Player, const int32 GroupID);

	UFUNCTION(BlueprintCallable)
		void EnableCrowd(bool isEnable);
private:
	virtual FVector GetCrowdAgentLocation() const override;


	virtual FVector GetCrowdAgentVelocity() const override;


	virtual void GetCrowdAgentCollisions(float& CylinderRadius, float& CylinderHalfHeight) const override;


	virtual float GetCrowdAgentMaxSpeed() const override;


	virtual int32 GetCrowdAgentAvoidanceGroup() const override;


	virtual int32 GetCrowdAgentGroupsToAvoid() const override;


	virtual int32 GetCrowdAgentGroupsToIgnore() const override;
};
