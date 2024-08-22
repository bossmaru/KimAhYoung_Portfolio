// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPlayerManager.generated.h"

UENUM(BlueprintType)
enum class EPlayerType : uint8
{
	Knight UMETA(DisplayName = "Knight"),
	Archer UMETA(DisplayName = "Archer")
};

UCLASS()
class TEAMHOMEWORK_API AMyPlayerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPlayerManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UClass* SetDefaultPawnClass();

	void SetPlayerType(EPlayerType type);
	EPlayerType GetPlayerType() const;

private:
	EPlayerType _playerType;
};
