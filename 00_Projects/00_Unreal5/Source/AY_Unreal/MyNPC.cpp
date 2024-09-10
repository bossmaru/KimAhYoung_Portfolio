// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNPC.h"

#include "MyGameInstance.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "MyPlayer.h"
#include "MyPlayerController.h"
#include "MyHpBar.h"
#include "MyNPCUI.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

#include "Kismet/KismetMathLibrary.h"


AMyNPC::AMyNPC()
{
	PrimaryActorTick.bCanEverTick = true;

	_trigger = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger"));

	_trigger->SetupAttachment(RootComponent);
	_trigger->SetCollisionProfileName(TEXT("MyNPC"));
	_trigger->SetSphereRadius(150.0f);

	_npcUI = CreateDefaultSubobject<UWidgetComponent>(TEXT("NPCWIdget"));
	if (GetMesh())
	{
		_npcUI->SetupAttachment(GetMesh());
		_npcUI->SetWidgetSpace(EWidgetSpace::Screen);
		_npcUI->SetRelativeLocation(FVector(0.0f, 0.0f, 200.0f));
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> npcUI(
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprint/UI/MyNPCUI_BP.MyNPCUI_BP_C'")
	);
	if (npcUI.Succeeded())
	{
		_npcUI->SetWidgetClass(npcUI.Class);
	}
}

void AMyNPC::BeginPlay()
{
	Super::BeginPlay();
}

void AMyNPC::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	_trigger->OnComponentBeginOverlap.AddDynamic(this, &AMyNPC::OnMyCharacterOverlap);
	_trigger->OnComponentEndOverlap.AddDynamic(this, &AMyNPC::OnMyCharacterOverlapEnd);

	_hpBarWidget->SetVisibility(false);
	_hpBarWidget->Deactivate();

	_npcUI->InitWidget();
	_npcUI->SetVisibility(false);
}

void AMyNPC::OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	_player = Cast<AMyPlayer>(OtherActor);
	if (_player)
	{
		AMyPlayerController* controller = 
			Cast<AMyPlayerController>(_player->GetController());
		if(controller)
			_isOverlapped = true;
	}
}

void AMyNPC::OnMyCharacterOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	_isOverlapped = false;
	_player->MeetNPC(false);
	_player = nullptr;
}

void AMyNPC::CharacterOverlapped()
{
	if (_isOverlapped && _player != nullptr)
	{
		_player->MeetNPC(true);

		if (_player->IsViewStore())
			_npcUI->SetVisibility(false);
		else
			_npcUI->SetVisibility(true);
	}

	else
	{
		_npcUI->SetVisibility(false);
	}
}

void AMyNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CharacterOverlapped();
}
