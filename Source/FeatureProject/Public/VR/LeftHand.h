// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VR/Hand.h"
#include "LeftHand.generated.h"

/**
 * 
 */
UCLASS()
class FEATUREPROJECT_API ALeftHand : public AHand
{
	GENERATED_BODY()
protected:
	ALeftHand();
protected:
	//
	virtual void BeginPlay() override;
	virtual void Tick(float deltaSeconds) override;
	
	
	
	
};
