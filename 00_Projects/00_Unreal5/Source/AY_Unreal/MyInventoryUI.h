// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyItem.h"
#include "MyInventoryUI.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_OneParam(ItemDropIndexDelegate, int32);
DECLARE_MULTICAST_DELEGATE(ItemDropDelegate);
DECLARE_DELEGATE_OneParam(ItemUseIndexDelegate, int32);
DECLARE_MULTICAST_DELEGATE(ItemUseDelegate);

UCLASS()
class TEAMHOMEWORK_API UMyInventoryUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMyInventoryUI(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
	virtual bool Initialize();

	void SetButtons();
	
	void SetDefaultTexture();

	void SetItemImage(int32 inventoryIndex, AMyItem* item = nullptr);

	UFUNCTION()
	void DropItem();
	UFUNCTION()
	void UseItem();

	UFUNCTION()
	void SetTargetItem0();
	UFUNCTION()
	void SetTargetItem1();
	UFUNCTION()
	void SetTargetItem2();
	UFUNCTION()
	void SetTargetItem3();
	UFUNCTION()
	void SetTargetItem4();
	UFUNCTION()
	void SetTargetItem5();
	UFUNCTION()
	void SetTargetItem6();
	UFUNCTION()
	void SetTargetItem7();
	UFUNCTION()
	void SetTargetItem8();

	UFUNCTION()
	void ShowItem();

	//Delegate
	ItemUseDelegate itemUSE;
	ItemDropDelegate itemDROP;

	ItemUseIndexDelegate itemUseIndex;
	ItemDropIndexDelegate itemDropIndex;

	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* SlotGrid;

	UPROPERTY(meta = (BindWidget))
	TArray<class UUI_E_MyButton*> Button_;

	UPROPERTY(meta = (BindWidget))
	TArray<class UImage*> Image_;

	UPROPERTY(meta = (BindWidget))
	class UImage* Item_texture;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Text_itemName;

	UPROPERTY(meta = (BindWidget))
	class UButton* DropButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* UseButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Texture, meta = (AllowPrivateAccess = "true"))
	class UTexture2D* _defaultTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Texture, meta = (AllowPrivateAccess = "true"))
	FString _defaultText;

	UPROPERTY()
	class AMyItem* _targetItem;
	UPROPERTY()
	int32 _targetIndex = -1;
};
