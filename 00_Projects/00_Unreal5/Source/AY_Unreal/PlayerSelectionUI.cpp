// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSelectionUI.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"
#include "Components/Widget.h"
#include "Components/PanelWidget.h"
#include "Kismet/GameplayStatics.h"

#include "MyGameModeBase.h"
#include "MyGameInstance.h"
#include "MyPlayerManager.h"

void UPlayerSelectionUI::NativeConstruct()
{
    TArray<UWidget*> widgets;
    widgets = SlotGrid->GetAllChildren();

    for (UWidget* widget : widgets)
    {
        UButton* button = Cast<UButton>(widget);
        if (button)
        {
            FName buttonName = button->GetFName();  // GetFName()으로 이름을 가져옴
            button->SetIsEnabled(true);

            if (buttonName == FName("KnightButton"))
            {
                button->OnClicked.AddDynamic(this, &UPlayerSelectionUI::OnKnightButtonClicked);
            }
            else if (buttonName == FName("ArcherButton"))
            {
                button->OnClicked.AddDynamic(this, &UPlayerSelectionUI::OnArcherButtonClicked);
            }
        }
    }
}

void UPlayerSelectionUI::OnKnightButtonClicked()
{
    PlayerManager->SetPlayerType(EPlayerType::Knight);
    SetPlayer();
}

void UPlayerSelectionUI::OnArcherButtonClicked()
{
    PlayerManager->SetPlayerType(EPlayerType::Archer);
    SetPlayer();
}

void UPlayerSelectionUI::SetPlayer()
{
    auto gameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(this));
    if (gameMode)
    {
        gameMode->SetSelectedPlayer();
        SetVisibility(ESlateVisibility::Hidden);
    }
}
