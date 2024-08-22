#pragma once
class Creature
{
public:
	Creature(string name, int hp, int mp, int attack);
	virtual ~Creature(); // 여기 virtual 은 꼭 안붙여도 됨


	// 멤버함수 : 기능
	virtual void PreAttack(Creature* other);
	virtual void Attack(Creature* other) abstract; // 순수가상함수
	virtual void TakeDamage(int amount);
	const string& GetName();
	const int& GetMaxHp();
	const int& GetCurHp();
	const int& GetCurMp();
	const int& GetCurAtk();
	bool IsDead();
	bool AllDead(vector<Creature*> group);

protected: // 멤버변수 : 속성
	string _name;
	int _curHp;
	int _maxHp;
	int _mp;
	int _attack;
};

