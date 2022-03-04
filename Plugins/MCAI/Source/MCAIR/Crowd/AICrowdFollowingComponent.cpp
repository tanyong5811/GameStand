// Fill out your copyright notice in the Description page of Project Settings.


#include "AICrowdFollowingComponent.h"

UAICrowdFollowingComponent::UAICrowdFollowingComponent(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	bRotateToVelocity = false; //true
	bUpdateDirectMoveVelocity = false;
	//是否启动分离
	bEnableSeparation = true; //false
	//路径偏移
	bEnablePathOffset = true; //false
	bEnableOptimizeVisibility = false; //true
	bEnableOptimizeTopology = false; //true
	// 设定品质
	AvoidanceQuality = ECrowdAvoidanceQuality::High; //Low
	//分离权重
	SeparationWeight = 50.0f;  // Was 2
	//躲避碰撞体范围
	CollisionQueryRange = 600.0f; // Was 400
	bUseBlockDetection = false;
}
