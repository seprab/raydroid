#pragma once
#include "entity.h"
#include <vector>
class creature :
    public entity
{
public:
	creature(int _id);
	~creature();
	virtual void Update() override;
	virtual void Draw() override;
	virtual void Destroy() override;
	virtual void Attack(creature* target);

private:
	bool isAlly{ false };
	std::vector<int> itemsEquiped;
	int strength;
	int agility;
	double evasion;
	unsigned int xp;
};

