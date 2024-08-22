#pragma once

#include "Brick.h"

#define BALL_COUNT				20

class ArkPlayer
{
public:
	ArkPlayer();
	~ArkPlayer();

	void Update();
	void Render(HDC hdc);

	void BallCollision(shared_ptr<class PlaySetting> border);
	void GetItem(vector<vector<shared_ptr<Brick>>> bricks);
	void ActivateBonusBall(int ballCount);


private:
	vector<shared_ptr<class Ball>> _balls;
	shared_ptr<class Ball> _curBall;
	vector< shared_ptr<class Ball>> _bonusBalls;
	shared_ptr<class Bar> _bar;
};

