// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStoreUI.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"


void UMyStoreUI::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMyStoreUI::ToggleVisibility()
{
	AMyPlayerController* playerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (_isVisible)
	{
		this->SetVisibility(ESlateVisibility::Hidden);
		_isVisible = false;

		if (playerController != nullptr)
		{
			playerController->HideUI();
		}
	}
	else
	{
		this->SetVisibility(ESlateVisibility::Visible);
		_isVisible = true;

		if (playerController != nullptr)
		{
			playerController->ShowUI();
		}
	}
}
