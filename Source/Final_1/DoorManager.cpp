// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorManager.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ADoorManager::ADoorManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_door = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	RootComponent = _door;
	DoorProxVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("DoorProximityVolume"));
	DoorProxVolume->AttachToComponent(_door, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADoorManager::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateFunctionFloat.BindDynamic(this, &ADoorManager::UpdateTimelineComp);

	if (DoorTimelineFloatCurve)
	{
		DoorTimelineComp->AddInterpFloat(DoorTimelineFloatCurve, UpdateFunctionFloat);
	}

	DoorProxVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorManager::OnOverlapBegin);
	DoorProxVolume->OnComponentEndOverlap.AddDynamic(this, &ADoorManager::OnOverlapEnd);
}

// Called every frame
void ADoorManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorManager::UpdateTimelineComp(float Output)
{
	FRotator DoorNewRotation = FRotator(0.0f, Output, 0.f);
	_door->SetRelativeRotation(DoorNewRotation);
}

void ADoorManager::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	DoorTimelineComp->Play();
}

void ADoorManager::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	DoorTimelineComp->Reverse();
}