// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

#include "MyItem.h"

UMyGameInstance::UMyGameInstance()
{
	GetItemDataTable();
}

void UMyGameInstance::Init()
{
	Super::Init();

	FActorSpawnParameters params;
	params.Name = TEXT("UIManager");
	_uiManager = GetWorld()->SpawnActor<AMyUIManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);
	
	params.Name = TEXT("PlayerManager");
	_playerManager = GetWorld()->SpawnActor<AMyPlayerManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);

	params.Name = TEXT("vfxManager");
	_vfxManager = GetWorld()->SpawnActor<AVFX_Manager>(FVector::ZeroVector, FRotator::ZeroRotator, params);

	params.Name = TEXT("SoundManager");
	_soundManager = GetWorld()->SpawnActor<ASoundManager>(FVector::ZeroVector, FRotator::ZeroRotator, params);
}

void UMyGameInstance::GetItemDataTable()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> itemData
	(TEXT("/Script/Engine.DataTable'/Game/Blueprint/Data/ItemData.ItemData'"));

	if (itemData.Succeeded())
	{
		UDataTable* data = itemData.Object;
		int32 i = 0;
		while (true)
		{
			FItemData* itemdata = data->FindRow<FItemData>(*FString::FromInt(i), TEXT(""));
			if (itemdata == nullptr)
				break;
			FItemData item = *itemdata;
			_itemData.Add(i, item);

			i++;
		}
	}
}

FItemData UMyGameInstance::GetItemDataByCode(int32 code)
{
	return _itemData[code];
}

// FMyStatData* UMyGameInstance::GetStatDataByLevel(int level)
// {
// 	auto statData = _statTable->FindRow<FMyStatData>(*FString::FromInt(level), TEXT(""));
// 	return statData;
// }
