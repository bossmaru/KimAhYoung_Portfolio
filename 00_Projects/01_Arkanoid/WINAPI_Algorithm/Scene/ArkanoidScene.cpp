#include "pch.h"
#include "ArkanoidScene.h"
#include "Objects/Arkanoid/ArkPlayer.h"
#include "Objects/Arkanoid/PlaySetting.h"


#define BALL_COUNT				5

ArkanoidScene::ArkanoidScene()
{
	_player = make_shared<ArkPlayer>();
	_playSetting = make_shared<PlaySetting>();
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_player->Update();
	_playSetting->Update();

	_player->BallCollision(_playSetting);
	_player->GetItem(_playSetting->GetBricks());
}

void ArkanoidScene::Render(HDC hdc)
{
	_player->Render(hdc);
	_playSetting->Render(hdc);
}