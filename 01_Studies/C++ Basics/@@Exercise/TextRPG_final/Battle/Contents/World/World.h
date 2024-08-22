#pragma once
class World
{
public:
	enum PlayerType
	{
		KNIGHT = 1,
		ARCHER = 2,
		MAGE = 3
	};

	enum PlayMode
	{
		BATTLE = 1,
		HUNT = 2,
	};

	enum MonsterType
	{
		GOBLIN = 1,
	};

	enum Start
	{
		YES = 1,
		NO = 2
	};

	World();
	~World();

	// 고블린 외에 몬스터 클래스를 상속하는 "홉고블린" 만들기
	// 홉고블린은 플레이어 10명이 레이드하는 형식.
	// 한 번에 4명의 플레이어를 공격.
	// 어그로 시스템 구현 : 가장 데미지를 많이 준 상위 네 명의 플레이어를 공격.
	// 이미 죽은 플레이어는 공격하면 안됨


	void Init();
	void Start();
	void End();

	bool Battle();
	void Hunt();

	void SelectClass(int num, string name, Creature** creature);
	void PlayMode();
	void SelectMonster(int monsterType);
	void ClonePlayers();
	void BossBattle();
	void BattleWin();

	struct PlayerPair
	{
		Creature* _player;
		int _id;
		int _damage;
	};

private:

	Creature* _player;
	Creature* _computer;
	Creature* _monster;

	vector<Creature*> _monsters;
	vector<Creature*> _players;
	Creature* _boss;
};

