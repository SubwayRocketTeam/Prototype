#pragma once

#include <stdio.h>
#include "cocos2d.h"

class GameObject;

typedef struct AttackInfo {
	int damage;
	cocos2d::Vec2 position;

	virtual bool collision(GameObject* obj) = 0;
} AttackInfo;

typedef struct AttackInfoCircle : public AttackInfo {
	int radius;

	bool collision(GameObject* obj) override;
} AttackInfoCircle;

class AttackManager {
private:
	static AttackManager* instance;
	AttackManager();
	~AttackManager();

	std::vector<AttackInfo*>* toMobDamageVector;
	std::vector<AttackInfo*>* toUserDamageVector;
public:
	static AttackManager* getInstance();

	void attackFromUserToMob(int range, int damage, cocos2d::Vec2 position);
	void attackFromMobToUser(int range, int damage, cocos2d::Vec2 position);

	void clearMobDamageVector();
	void clearUserDamageVector();

	std::vector<AttackInfo*>* getMobDamageVector() const {
		return this->toMobDamageVector;
	}

	std::vector<AttackInfo*>* getUserDamageVector() const {
		return this->toUserDamageVector;
	}
};

