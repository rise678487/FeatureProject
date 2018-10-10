// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hand.generated.h"

class UMotionControllerComponent;
class USkeletalMeshComponent;
UCLASS()
class FEATUREPROJECT_API AHand : public AActor
{
	GENERATED_BODY()
	
protected:	
	// Sets default values for this actor's properties
	AHand();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
//Component
public:
	UPROPERTY()
		USceneComponent* Root;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "VR Components")
		UMotionControllerComponent* MC_hand;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VR Components")
		USkeletalMeshComponent* SK_hand;
	void SetTrackingSource(EControllerHand handType);
		

	
	
};
