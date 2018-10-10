// Fill out your copyright notice in the Description page of Project Settings.

#include "Hand.h"
#include "Components/SkeletalMeshComponent.h"
#include "MotionControllerComponent.h"

// Sets default values
AHand::AHand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	MC_hand = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MC_hand"));
	MC_hand->SetupAttachment(GetRootComponent());
	SK_hand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_hand"));
	SK_hand->SetupAttachment(MC_hand);
	MC_hand->bDisplayDeviceModel = true;
}

// Called when the game starts or when spawned
void AHand::BeginPlay()
{
	Super::BeginPlay();
	if (!SK_hand)
	{
		
	}
}

// Called every frame
void AHand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHand::SetTrackingSource(EControllerHand handType)
{
	MC_hand->SetTrackingSource(handType);
}

