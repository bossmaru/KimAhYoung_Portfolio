#pragma once
class Mage : public Player
{
public:
	Mage(string name, int hp, int mp, int attack);
	virtual ~Mage();

	// Player을(를) 통해 상속됨
	virtual void PreAttack(Creature* other) override;
	virtual void Attack(Creature* other) override;
	virtual void GetExp(int amount) override;

};
