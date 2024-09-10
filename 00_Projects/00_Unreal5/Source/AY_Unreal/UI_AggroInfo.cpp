// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_AggroInfo.h"
#include "MyPlayer.h"
#include "Components/Widget.h"
#include "Components/VerticalBox.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UUI_AggroInfo::NativeConstruct()
{ 
}

void UUI_AggroInfo::SetPlayerInfo(TArray<TTuple<AMyPlayer*, int32>> players)
{
	TArray<UWidget*> damageBars = DamageBox->GetAllChildren();
	for (int32 i = 0; i < damageBars.Num(); i++)
	{
		UProgressBar* damageBar = Cast<UProgressBar>(damageBars[i]);
		if (damageBar)
		{
			if (i < players.Num())
			{
				_playerIndex.Add(players[i].Key, i);
				_damageInfo.Add(i, damageBar);
			}
		}
	}

	TArray<UWidget*> hpBars = HpBox->GetAllChildren();
	for (int32 i = 0; i < hpBars.Num(); i++)
	{
		UProgressBar* hpBar = Cast<UProgressBar>(hpBars[i]);
		if (hpBar)
		{
			_hpInfo.Add(i, hpBar);
		}
	}

	TArray<UWidget*> pName = NameBox->GetAllChildren();
	for (int32 i = 0; i < pName.Num(); i++)
	{
		UTextBlock* playerName = Cast<UTextBlock>(pName[i]);
		if (playerName)
		{
			FString playername;
			if (i < players.Num())
			{
				playername = FString(TEXT("Player") + FString::FromInt(i));
			}
			else
			{
				playername = FString(TEXT("N/A"));
			}
			playerName->SetText(FText::FromString(playername));
			_playerName.Add(i, playerName);
		}
	}
}

void UUI_AggroInfo::SetDamageValue(float dmg, AMyPlayer* player)
{

	if (int32* index = _playerIndex.Find(player))
	{
		if (*index >= 0)
		{
			UProgressBar** progressBarPtr = _damageInfo.Find(*index);

			if (*progressBarPtr)
			{
				// 새로운 데미지를 누적합니다.
				float newPercent = dmg / 100;

				// ProgressBar의 Percent를 업데이트합니다.
				(*progressBarPtr)->SetPercent(newPercent);
			}
		}
	}
}

void UUI_AggroInfo::SetHpValue(float ratio, int32 index)
{
	for (auto& elem : _damageInfo)
	{
		UProgressBar* bar = elem.Value;
		bar->SetFillColorAndOpacity(FLinearColor::Black);
	}

	for (auto& elem : _hpInfo)
	{
		UProgressBar* bar = elem.Value;
		bar->SetFillColorAndOpacity(FLinearColor::Black);
	}

	if (UProgressBar** progressBarPtr = _hpInfo.Find(index))
	{
		if (*progressBarPtr)
		{
			(*progressBarPtr)->SetPercent(ratio);
			(*progressBarPtr)->SetFillColorAndOpacity(FLinearColor::Red);

		}
	}

	if (UProgressBar** progressBarPtr = _damageInfo.Find(index))
	{
		if (*progressBarPtr)
		{
			(*progressBarPtr)->SetFillColorAndOpacity(FLinearColor::Green);
		}
	}
}
