// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UENUM()
enum class TYPE
{
	HP,
	ATK,
	SPEED,
	GOLD,
};

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTexture2D* textuer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMesh* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemCode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TYPE type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 statAddValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 price;
};

DECLARE_MULTICAST_DELEGATE_OneParam(ItemOverlap, class AMyItem*);
DECLARE_MULTICAST_DELEGATE_OneParam(ItemOverlapEnd, class AMyItem*);

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

	void Init();
	void Disable();

	UFUNCTION()
	void OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnMyCharacterOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	void InitItemByCode(int32 code);

	void SetItemOwner(class AMyPlayer* player);
	void ReleaseItem(FVector location, FRotator rotation = FRotator::ZeroRotator);
	void UseItem();

	//Getter
	class UTexture2D* GetItemTexture();
	class UStaticMesh* GetItemMesh();
	FString GetItemName();
	int32 GetItemPrice();

	ItemOverlap ItemOverlapDelegate;
	ItemOverlapEnd OverlapEndDelegate;

private:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* _meshComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* _trigger;

	UPROPERTY()
	class AMyPlayer* _player;
	UPROPERTY()
	class AMyPlayer* _owner;

	//Item Description
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info, meta = (AllowPrivateAccess = "true"))
	FString _name;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info, meta = (AllowPrivateAccess = "true"))
	class UTexture2D* _textuer;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info, meta = (AllowPrivateAccess = "true"))
	class UStaticMesh* _mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info, meta = (AllowPrivateAccess = "true"))
	TYPE _type;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info, meta = (AllowPrivateAccess = "true"))
	int32 _statAddValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Info, meta = (AllowPrivateAccess = "true"))
	int32 _price;
};
