#pragma once

#include <stdio.h>
#include "cocos2d.h"

class GameObject;

typedef struct AttackInfoCircle {
	int radius;
	int damage;
	cocos2d::Vec2 position;
} AttackInfoCircle;

class AttackManager {
private:
	static AttackManager* instance;
	AttackManager();
	~AttackManager();

	std::vector<AttackInfoCircle>* toMobDamageVector;
	std::vector<AttackInfoCircle>* toUserDamageVector;
public:
	static AttackManager* getInstance();

	void attackFromUserToMob(int range, int damage, cocos2d::Vec2 position);
	void attackFromMobToUser(int range, int damage, cocos2d::Vec2 position);

	void clear();

	std::vector<AttackInfoCircle>* getMobDamageVector() const {
		return this->toMobDamageVector;
	}

	std::vector<AttackInfoCircle>* getUserDamageVector() const {
		return this->toUserDamageVector;
	}
};

