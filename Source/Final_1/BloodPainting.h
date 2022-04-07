// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloodPainting.generated.h"

UCLASS()
class FINAL_1_API ABloodPainting : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, EditFixedSize)
	class UStaticMeshComponent* _painting;
	
public:	
	// Sets default values for this actor's properties
	ABloodPainting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
