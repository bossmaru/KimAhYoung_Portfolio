// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "BossMonster.h"
//Game Instance
#include "MyGameInstance.h"
//Camera
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
//Input
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "MyPlayerController.h"
//Components
#include "MyStatComponent.h"
#include "MyInventoryComponent.h"
#include "MyItem.h"
//Anim
#include "MyAnimInstance.h"
//UI
#include "MyUIManager.h"
#include "MyPlayerManager.h"
#include "MyInventoryUI.h"

#include "Kismet/GameplayStatics.h"

AMyPlayer::AMyPlayer()
{
	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));
}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	SetAnimation();
	SetTickableWhenPaused(true);

	if (_controller->IsLocalPlayerController())
	{
		UIManager->OpenUI(UI_List::BaseDisplay);
	}

	
}

void AMyPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	_controller = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyPlayer::Move);

		// Looking
		EnhancedInputComponent->BindAction(_turnAction, ETriggerEvent::Triggered, this, &AMyPlayer::Turn);
		EnhancedInputComponent->BindAction(_lookUpAction, ETriggerEvent::Triggered, this, &AMyPlayer::LookUp);

		// Jumping
		EnhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Started, this, &AMyPlayer::JumpA);

		// Attack
		EnhancedInputComponent->BindAction(_attackAction, ETriggerEvent::Triggered, this, &AMyPlayer::AttackA);

		// Get Item
		EnhancedInputComponent->BindAction(_getItemAction, ETriggerEvent::Started, this, &AMyPlayer::TryGetItem);
		EnhancedInputComponent->BindAction(_getItemAction, ETriggerEvent::Completed, this, &AMyPlayer::TryGetItemEnd);

		// Drop Item
		EnhancedInputComponent->BindAction(_dropItemAction, ETriggerEvent::Started, this, &AMyPlayer::DropItem);

		// View Inventory
		EnhancedInputComponent->BindAction(_viewInventoryAction, ETriggerEvent::Started, this, &AMyPlayer::ViewInventory);
		
		// View Store
		EnhancedInputComponent->BindAction(_viewStoreAction, ETriggerEvent::Started, this, &AMyPlayer::ViewStore);
	}
}

void AMyPlayer::ShowUI(bool bGamePaused)
{
	if (_controller == nullptr)
		return;

	FInputModeGameAndUI inputMode;
	_controller->SetInputMode(inputMode);
	_UIopen = true;
	_controller->bShowMouseCursor = true;
	_controller->SetPause(bGamePaused);
}

void AMyPlayer::HideUI()
{
	if (_controller == nullptr)
		return;

	FInputModeGameOnly inputMode;
	_controller->SetInputMode(inputMode);
	_UIopen = false;
	_controller->bShowMouseCursor = false;
	_controller->SetPause(false);
}

void AMyPlayer::AttackHit()
{
	if (_UIopen)
		return;
}

void AMyPlayer::Move(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();
	if (Controller != nullptr && !_UIopen)
	{
		// add movement 
		_vertical = MovementVector.Y;
		_horizontal = MovementVector.X;

		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMyPlayer::Turn(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr && !_UIopen)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
}

void AMyPlayer::LookUp(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();
	if (Controller != nullptr && !_UIopen)
	{
		AddControllerPitchInput(LookAxisVector.X);
	}
}

void AMyPlayer::JumpA(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed && !_UIopen)
	{
		ACharacter::Jump();
		FVector MoveMentVector = GetActorLocation();
		_height = MoveMentVector.Z;
	}
}

void AMyPlayer::AttackA(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();
	
	if (isPressed && _isAttacking == false && _animInstance != nullptr && !_UIopen)
	{
		_animInstance->PlayAttackMontage();
		_isAttacking = true;
	
		_curAttackIndex %= 3;
		_curAttackIndex++;
		_animInstance->JumpToSection(_curAttackIndex);
	}
}

void AMyPlayer::ViewInventory(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();
	
	if (isPressed && !_viewStore)
	{
		if (!_UIopen)
		{
			UIManager->OpenUI(UI_List::Inventory);
			ShowUI(false);
		}
		else 
		{
			UIManager->CloseUI(UI_List::Inventory);
			HideUI();
		}
	}
}

void AMyPlayer::ViewStore(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed && _meetNPC && !_inventoryOpen)
	{
		UE_LOG(LogTemp, Warning, TEXT("view store"));

		if (_UIopen)
		{
			UIManager->CloseUI(UI_List::Store);
			UIManager->CloseUI(UI_List::Inventory);
			HideUI();
		}
		else
		{
			UIManager->OpenUI(UI_List::Store);
			UIManager->OpenUI(UI_List::Inventory);
			ShowUI(false);
		}
	}
}

void AMyPlayer::TryGetItem(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed)
	{
		_tryGetItem = true;
		UE_LOG(LogTemp, Display, TEXT("Try get Item"));
	}
}

void AMyPlayer::TryGetItemEnd(const FInputActionValue& value)
{
	_tryGetItem = false;
}

void AMyPlayer::SetTargitItem(AMyItem* item)
{
	_item = item;
}

void AMyPlayer::AddItem(AMyItem* item)
{
	if (item == nullptr)
		return;
	_inventoryCom->AddItem(item);
	item->SetOwner(this);
}

void AMyPlayer::DropItem(const FInputActionValue& value)
{
	_inventoryCom->DropItem();
	
}