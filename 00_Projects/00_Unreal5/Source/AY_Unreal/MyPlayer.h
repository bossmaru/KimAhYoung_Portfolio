// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "MyGameInstance.h"
#include "MyPlayer.generated.h"

/**
 * 
 */


UCLASS()
class TEAMHOMEWORK_API AMyPlayer : public ACreature
{
	GENERATED_BODY()

public:
	AMyPlayer();

public:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ShowUI(bool bGamePaused);
	void HideUI();

	virtual void AttackHit() override;

	void Move(const FInputActionValue& value);
	void Turn(const FInputActionValue& value);
	void LookUp(const FInputActionValue& value);
	void JumpA(const FInputActionValue& value);
	void AttackA(const FInputActionValue& value);
	void ViewInventory(const FInputActionValue& value);
	void ViewStore(const FInputActionValue& value);

	void TryGetItem(const FInputActionValue& value);
	void TryGetItemEnd(const FInputActionValue& value);

	//inventory func
	UFUNCTION()
	void SetTargitItem(class AMyItem* item);
	void AddItem(class AMyItem* item);
	void DropItem(const FInputActionValue& value);

	//npc func
	void MeetNPC(bool answer) { _meetNPC = answer; }
	bool IsMeetNPC() { return _meetNPC; }
	bool IsViewStore() { return _viewStore; }

	//boss func
	int32 TakenDamageAmount() { return _damageToBoss; }
	void DamagedByBoss(bool result) { _damagedByBoss = result; }
	bool IsDamagedByBoss() { return _damagedByBoss; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	bool _tryGetItem = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
	bool _meetNPC = false;

	//UI key
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
	bool _viewStore = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
	bool _inventoryOpen = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI, meta = (AllowPrivateAccess = "true"))
	bool _UIopen = false;

	// Controller
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Controller, meta = (AllowPrivateAccess = "true"))
	class AMyPlayerController* _controller;

	UPROPERTY()
	class AMyItem* _item;

	// Action
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _moveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _turnAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _lookUpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _jumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _attackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _getItemAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _dropItemAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _viewInventoryAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* _viewStoreAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpringArm, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* _springArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* _camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	int32 _damageToBoss = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	bool _damagedByBoss = false;

	FTimerHandle damageResetTimerHandle;
};