#include "pch.h"
#include "ArkPlayer.h"
#include "Bar.h"
#include "Ball.h"
#include "Brick.h"
#include "PlaySetting.h"

ArkPlayer::ArkPlayer()
{
	_bar = make_shared<Bar>();
	_balls.reserve(BALL_COUNT);
	_bonusBalls.reserve(3);
	for (int i = 0; i < BALL_COUNT; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_balls.push_back(ball);
	}
	for (int i = 0; i < 3; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_bonusBalls.push_back(ball);
	}

	_curBall = _balls[0];
}

ArkPlayer::~ArkPlayer()
{
}

void ArkPlayer::Update()
{
	_bar->Update();

	if (!_curBall->_start)
	{
		_curBall->_center._x = _bar->_center._x;
	}

	if (!_curBall->_isActive)
	{
		auto iter = std::find_if(_balls.begin(), _balls.end(),
			[](shared_ptr<Ball> ball)->bool
			{
				if (!ball->_isUsed) return true;
				return false;
			});

		if (iter != _balls.end())
		{
			(*iter)->_start = true;
			(*iter)->_isActive = true;
			(*iter)->_isUsed = true;
			_curBall = (*iter);
			return;

		}
	}

	for (auto ball : _bonusBalls)
	{
		if (ball->_isActive)
		{
			ball->Update();
		}
	}

	_curBall->Update();
}

void ArkPlayer::Render(HDC hdc)
{
	_bar->Render(hdc);
	if (_curBall->_isActive)
	{
		_curBall->Render(hdc);
	}
	for (auto ball : _bonusBalls)
	{
		if (ball->_isActive)
		{
			ball->Render(hdc);
		}
	}
}

void ArkPlayer::BallCollision(shared_ptr<PlaySetting> border)
{
	_curBall->BorderCollision(border->GetWalls());
	_curBall->BrickCollision(border->GetBricks());
	_curBall->BarCollision(_bar);
	_curBall->OutofWindow(border->GetWalls());

	for (auto ball : _bonusBalls)
	{
		if (ball->_isActive)
		{
			ball->BorderCollision(border->GetWalls());
			ball->BrickCollision(border->GetBricks());
			ball->BarCollision(_bar);
			ball->OutofWindow(border->GetWalls());
		}
	}
}

void ArkPlayer::GetItem(vector<vector<shared_ptr<Brick>>> bricks)
{
	for (auto brick_X : bricks)
	{
		for (auto brick : brick_X)
		{
			shared_ptr<Item> item = brick->GetItem();

			if (!item || !item->IsCollision(_bar))
				continue;

			item->SetUsed(true);

			switch (item->GetItemType())
			{
			case ItemType::LongBar:
				_bar->ChangeSize(Vector2(Bar_Width * 1.15, Bar_Height));
				break;

			case ItemType::DoubleBall:
				ActivateBonusBall(1);
				break;

			case ItemType::TripleBall:
				ActivateBonusBall(2);
				break;

			default:
				break;
			}
		}
	}
}

void ArkPlayer::ActivateBonusBall(int ballCount)
{
	for (int i = 0; i < ballCount; ++i)
	{
		for (auto& ball : _bonusBalls)
		{
			if (!ball->_isUsed)
			{
				ball->_center._x = _bar->_center._x;
				ball->_start = true;
				ball->_isActive = true;
				ball->_isUsed = true;
				break;
			}
		}
	}
}