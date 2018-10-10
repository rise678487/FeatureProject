// Fill out your copyright notice in the Description page of Project Settings.

#include "RightHand.h"
#include "MotionControllerComponent.h"

ARightHand::ARightHand()
{
	PrimaryActorTick.bCanEverTick = true;
	SetTrackingSource(EControllerHand::Right);

}

void ARightHand::BeginPlay()
{
	Super::BeginPlay();
	
}
