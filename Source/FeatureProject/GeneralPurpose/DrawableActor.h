// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawableActor.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;
class UTextureRenderTarget2D;

UCLASS()
class FEATUREPROJECT_API ADrawableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADrawableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components")
		UStaticMeshComponent* SM_DrawableMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		UMaterial* M_WhiteBoard;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UMaterial* M_BrushMasker;
	UPROPERTY()
		UMaterialInstanceDynamic* Inst_WhiteBoard;
	UPROPERTY()
		UMaterialInstanceDynamic* Inst_BrushMasker;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		UTextureRenderTarget2D* RT_DrawableBoard;
	UFUNCTION()
		void DrawOnObject(const FVector2D& brushLocation, const float brushSize);
		


	
	
};
