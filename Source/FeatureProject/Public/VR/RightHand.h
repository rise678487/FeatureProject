// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VR/Hand.h"
#include "RightHand.generated.h"

/**
 * 
 */
UCLASS()
class FEATUREPROJECT_API ARightHand : public AHand
{
	GENERATED_BODY()
protected:
	ARightHand();
protected:
	//
	virtual void BeginPlay() override;
	
	
	
	
};
