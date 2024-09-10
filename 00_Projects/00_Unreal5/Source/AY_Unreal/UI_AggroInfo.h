// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_AggroInfo.generated.h"

/**
 * 
 */
UCLASS()
class TEAMHOMEWORK_API UUI_AggroInfo : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	void SetPlayerInfo(TArray<TTuple<class AMyPlayer*, int32>> players);
	void SetDamageValue(float dmg, class AMyPlayer* player);
	void SetHpValue(float ratio, int32 index);

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* NameBox;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* DamageBox;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* HpBox;

	UPROPERTY()
	TMap<class AMyPlayer*, int32> _playerIndex;

	UPROPERTY()
	TMap<int32, class UTextBlock*> _playerName;

	UPROPERTY()
	TMap<int32, class UProgressBar*> _damageInfo;

	UPROPERTY()
	TMap<int32, class UProgressBar*> _hpInfo;
};
