// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

UCLASS()
class TEAMHOMEWORK_API ASoundManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CreateSoundClass(FString name, FString path);
	void CreateSoundPool();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Play(FString name, FVector location, FRotator rotator = FRotator::ZeroRotator);


private:
	int32 _poolCount = 10;

	UPROPERTY()
	TMap<FString, TSubclassOf<class USoundBase>> _classTable;

	TMap<FString, TArray<USoundBase*>> _soundTable;

	UPROPERTY()
	class USceneComponent* _rootComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UAudioComponent* _audioCom;
};
