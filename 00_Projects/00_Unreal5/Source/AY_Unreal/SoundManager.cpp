// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundManager.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
ASoundManager::ASoundManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	_rootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = _rootComponent;

	_audioCom = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	_audioCom->SetupAttachment(_rootComponent);

	// 사운드 풀 초기화
	CreateSoundClass(TEXT("ArcherAttack"), TEXT("/Script/Engine.SoundCue'/Game/ParagonSparrow/Audio/Cues/Sparrow_Effort_Attack.Sparrow_Effort_Attack'"));
	CreateSoundClass(TEXT("KnightAttack"), TEXT("/Script/Engine.SoundCue'/Game/ParagonSunWukong/Audio/Cues/Wukong_Effort_Attack.Wukong_Effort_Attack'"));
	CreateSoundClass(TEXT("MonsterAttack"), TEXT("/Script/Engine.SoundCue'/Game/ParagonKhaimera/Characters/Heroes/Khaimera/Sounds/SoundCues/Khaimera_Effort_Attack.Khaimera_Effort_Attack'"));
	CreateSoundClass(TEXT("BossAttack"), TEXT("/Script/Engine.SoundCue'/Game/ParagonBoris/Audio/Cues/Boris_Effort_Attack.Boris_Effort_Attack'"));
}

// Called when the game starts or when spawned
void ASoundManager::BeginPlay()
{
	Super::BeginPlay();
	
	CreateSoundPool();
}

void ASoundManager::CreateSoundClass(FString name, FString path)
{
	if (_classTable.Contains(name))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s already exists in the sound class table"), *name);
		return;
	}

	ConstructorHelpers::FObjectFinder<USoundBase> sound(*path);
	if (sound.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("Successfully loaded sound: %s"), *name);
		_classTable.Add(name, sound.Object->GetClass());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load sound: %s at path: %s"), *name, *path);
	}
}

void ASoundManager::CreateSoundPool()
{
	for (auto& classPair : _classTable)
	{
		FString soundName = classPair.Key;
		_soundTable.Add(soundName);

		for (int32 i = 0; i < _poolCount; i++)
		{
			FString tempName = FString::Printf(TEXT("%s_%d"), *soundName, i);
			USoundBase* newSound = Cast<USoundBase>(NewObject<USoundBase>(this, classPair.Value));

			if (newSound)
			{
				_soundTable[soundName].Add(newSound);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to create sound instance for: %s"), *soundName);
			}
		}
	}
}

// Called every frame
void ASoundManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASoundManager::Play(FString name, FVector location, FRotator rotator)
{
	if (!_soundTable.Contains(name))
	{
		UE_LOG(LogTemp, Error, TEXT("Sound not found in the table: %s"), *name);
		return;
	}

	// 플레이어의 위치를 가져옵니다.
	//APlayerController* playerController = UGameplayStatics::GetPlayerController(this, 0);
	//if (playerController)
	//{
	//	APawn* playerPawn = playerController->GetPawn();
	//	if (playerPawn)
	//	{
	//		FVector playerLocation = playerPawn->GetActorLocation();

	//		// 플레이어 위치 근처에서 소리를 재생하도록 위치를 설정
	//		FVector soundLocation = playerLocation + FVector(200.0f, 200.0f, 0.0f);  // 플레이어 위치에서 약간 떨어진 곳

	//		USoundBase** availableSound = _soundTable[name].FindByPredicate([](USoundBase* sound) -> bool
	//			{
	//				return sound != nullptr;
	//			});

	//		if (availableSound && *availableSound)
	//		{
	//			UGameplayStatics::PlaySoundAtLocation(this, *availableSound, soundLocation, rotator);
	//			UE_LOG(LogTemp, Log, TEXT("Playing sound: %s at player location: %s"), *name, *soundLocation.ToString());
	//		}
	//		else
	//		{
	//			UE_LOG(LogTemp, Warning, TEXT("No available sound to play for: %s"), *name);
	//		}
	//	}
	//}
}

