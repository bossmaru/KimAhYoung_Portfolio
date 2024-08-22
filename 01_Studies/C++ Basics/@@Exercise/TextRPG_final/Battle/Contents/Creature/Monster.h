#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int mp, int attack);
	virtual ~Monster(); // virtual 붙여줘야함

	virtual void Attack(Creature* other);
	virtual void TakeDamage(int amount);

	void MonstersAttack(Player* player, vector<Creature*> group);

protected:
};


