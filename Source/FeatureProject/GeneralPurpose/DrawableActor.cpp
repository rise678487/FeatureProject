// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawableActor.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/KismetRenderingLibrary.h"
#include "Engine/TextureRenderTarget2D.h"


// Sets default values
ADrawableActor::ADrawableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_DrawableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_DrawableMesh"));
	SetRootComponent(SM_DrawableMesh);
	static ConstructorHelpers::FObjectFinder<UMaterial> M_Drawable(TEXT("Material'/Game/VR/Material/WhiteBoard/M_WhiteBoard.M_WhiteBoard'"));
	if (M_Drawable.Succeeded())
	{
		M_WhiteBoard = M_Drawable.Object;
		Inst_WhiteBoard = UMaterialInstanceDynamic::Create(M_WhiteBoard, SM_DrawableMesh);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Mesh(TEXT("StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	if (SM_Mesh.Succeeded())
	{
		SM_DrawableMesh->SetStaticMesh(SM_Mesh.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> M_Brush(TEXT("Material'/Game/VR/Material/WhiteBoard/M_BrushMasker.M_BrushMasker'"));
	if (M_Brush.Succeeded())
	{
		Inst_BrushMasker = UMaterialInstanceDynamic::Create(M_BrushMasker,SM_DrawableMesh);
	}
	static ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> RT_FindDrawableBoard(TEXT("CanvasRenderTarget2D'/Game/VR/Texture/WhiteBoard/RT_WhiteBoard.RT_WhiteBoard'"));
	if (RT_FindDrawableBoard.Succeeded())
	{
		RT_DrawableBoard = RT_FindDrawableBoard.Object;
	}

}

// Called when the game starts or when spawned
void ADrawableActor::BeginPlay()
{
	Super::BeginPlay();
	if (SM_DrawableMesh)
	{
		SM_DrawableMesh->SetMaterial(0, Inst_WhiteBoard);
	}
	UKismetRenderingLibrary::ClearRenderTarget2D(this, RT_DrawableBoard);
	
}

// Called every frame
void ADrawableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADrawableActor::DrawOnObject(const FVector2D & brushLocation, const float brushSize)
{
	Inst_BrushMasker->SetVectorParameterValue("BrushLocation", FLinearColor(brushLocation.X, brushLocation.Y, 0));
	Inst_BrushMasker->SetScalarParameterValue("BrushSize", brushSize);
	UKismetRenderingLibrary::DrawMaterialToRenderTarget(this, RT_DrawableBoard, Inst_BrushMasker);
}

