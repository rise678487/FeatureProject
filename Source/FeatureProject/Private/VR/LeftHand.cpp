// Fill out your copyright notice in the Description page of Project Settings.

#include "LeftHand.h"
#include "MotionControllerComponent.h"

ALeftHand::ALeftHand()
{ 
	PrimaryActorTick.bCanEverTick = true;
}

void ALeftHand::BeginPlay()
{
	Super::BeginPlay();
	SetTrackingSource(EControllerHand::Left);
}

void ALeftHand::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);
}

