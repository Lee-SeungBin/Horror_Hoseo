// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointLightManager.generated.h"

UCLASS()
class FINAL_1_API APointLightManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointLightManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightManager")
	class UPointLightComponent* _pointlight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightManager")
	class UStaticMeshComponent* _lightmesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LightManager")
	float LightIntensity;

	UFUNCTION(BlueprintCallable, Category = "LightManager")
	void TurnOff();
};
