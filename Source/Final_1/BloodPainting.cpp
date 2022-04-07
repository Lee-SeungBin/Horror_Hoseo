// Fill out your copyright notice in the Description page of Project Settings.


#include "BloodPainting.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABloodPainting::ABloodPainting()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_painting = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("soundmesh"));
	RootComponent = _painting;
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMesh(TEXT("/Engine/BasicShapes/Plane.Plane"));
	_painting->SetStaticMesh(PlaneMesh.Object);
}

// Called when the game starts or when spawned
void ABloodPainting::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloodPainting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

