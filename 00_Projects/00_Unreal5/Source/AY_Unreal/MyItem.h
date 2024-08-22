// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

USTRUCT()
struct FItemType
{
	GENERATED_BODY()

	FItemType() { _texture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/Icons/Tex_Default.Tex_Default'")); };

	UPROPERTY()
	class UTexture2D* _texture;
};


USTRUCT()
struct FItemDetail
{
	GENERATED_BODY()

	FItemDetail() { _itemType = FItemType(); };

	FItemType _itemType;
};

UCLASS()
class TEAMHOMEWORK_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnMyCharacterOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void CharacterOverlapped();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* _meshComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* _trigger;

	UPROPERTY()
	bool _isOverlapped;

	UPROPERTY()
	class AMyPlayer* _player;

	FItemType _itemType;
};
