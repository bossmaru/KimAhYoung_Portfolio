// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VFX_Manager.generated.h"

class AEffect;

UCLASS()
class TEAMHOMEWORK_API AVFX_Manager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVFX_Manager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CreateParticleClass(FString name, FString path);
	void CreateEffect();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Play(FString name, FVector location, FRotator rotator = FRotator::ZeroRotator);

private:
	int32 _poolCount = 20;

	UPROPERTY()
	TMap<FString, TSubclassOf<class AEffect>> _classTable;

	TMap<FString, TArray<class AEffect*>> _effectTable;

	UPROPERTY()
	class USceneComponent* _rootComponent;
};
