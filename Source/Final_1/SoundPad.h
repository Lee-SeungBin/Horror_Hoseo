// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundPad.generated.h"

UCLASS()
class FINAL_1_API ASoundPad : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, EditFixedSize)
	class UBoxComponent* trigger_box;

	UPROPERTY(EditInstanceOnly)
	class UStaticMeshComponent* _mesh;
public:
	UFUNCTION(BlueprintImplementableEvent)
	void overlapAction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAudioComponent* _sound;
private:
	UFUNCTION()
		void OnOverlapEvent(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);


public:	
	// Sets default values for this actor's properties
	ASoundPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
