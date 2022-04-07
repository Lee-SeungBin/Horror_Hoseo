// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundPad.h"
#include "PointLightManager.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"

// Sets default values
ASoundPad::ASoundPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	trigger_box = CreateDefaultSubobject<UBoxComponent>(TEXT("triggerbox"));
	trigger_box->SetGenerateOverlapEvents(true);
	RootComponent = trigger_box;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("soundmesh"));
	_mesh->SetupAttachment(RootComponent);

	_sound = CreateDefaultSubobject<UAudioComponent>(TEXT("sound"));
	_sound->SetupAttachment(RootComponent);
	_sound->SetAutoActivate(false);
}

// Called when the game starts or when spawned
void ASoundPad::BeginPlay()
{
	Super::BeginPlay();
	
	FScriptDelegate overlap_delegate;
	overlap_delegate.BindUFunction(this, FName("OnOverlapEvent"));
	
	trigger_box->OnComponentBeginOverlap.Add(overlap_delegate);
}

// Called every frame
void ASoundPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASoundPad::OnOverlapEvent(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	this->overlapAction();
	this->Destroy();
	_sound->Play();
}