// Fill out your copyright notice in the Description page of Project Settings.


#include "PointLightManager.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APointLightManager::APointLightManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_lightmesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("LightMesh"));
	RootComponent = _lightmesh;

	_pointlight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	_pointlight->Intensity = LightIntensity;
	_pointlight->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APointLightManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APointLightManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APointLightManager::TurnOff()
{
	_pointlight->DestroyComponent();
}
