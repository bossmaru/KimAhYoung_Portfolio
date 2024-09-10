// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyUIManager.h"
#include "MyPlayerManager.h"
#include "VFX_Manager.h"
#include "SoundManager.h"
#include "MyItem.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

#define UIManager Cast<UMyGameInstance>(GetWorld()->GetGameInstance())->GetUIManager()
#define PlayerManager Cast<UMyGameInstance>(GetWorld()->GetGameInstance())->GetPlayerManager()
#define VFXManager Cast<UMyGameInstance>(GetGameInstance())->GetVFXManager()
#define SoundManager Cast<UMyGameInstance>(GetGameInstance())->GetSoundManager()

struct FItemData;

UCLASS()
class TEAMHOMEWORK_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

private:
	virtual void Init() override;
	void GetItemDataTable();
public:
	// FMyStatData* GetStatDataByLevel(int level);
	FItemData GetItemDataByCode(int32 code);

	class AMyUIManager* GetUIManager() { return _uiManager; };
	class AMyPlayerManager* GetPlayerManager() { return _playerManager; };
	class AVFX_Manager* GetVFXManager() { return _vfxManager; };
	class ASoundManager* GetSoundManager() { return _soundManager; };

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class AMyUIManager* _uiManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class AMyPlayerManager* _playerManager;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class AVFX_Manager* _vfxManager;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class ASoundManager* _soundManager;

	//Data Table
	UPROPERTY()
	class UDataTable* _statTable;

	UPROPERTY()
	TMap<int32, FItemData> _itemData;
};
