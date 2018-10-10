// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ARightHand;
class ALeftHand;
class AHand;

UCLASS()
class FEATUREPROJECT_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, Category = "VR Components")
		USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "VR Components")
		UCameraComponent* cameraComp;
	UPROPERTY(EditAnywhere, Category = "VR Components")
		TSubclassOf<ARightHand> rightHandClass;
	UPROPERTY(EditAnywhere, Category = "VR Components")
		TSubclassOf<ALeftHand> leftHandClass;
	UPROPERTY()
		ARightHand* rightHand;
	UPROPERTY()
		ALeftHand* leftHand;



	
	
};