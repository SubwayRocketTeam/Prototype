#pragma once

#include <stdio.h>
#include "cocos2d.h"

class GameObject;
class Character;
class Sheep;

struct AttackInfo {
	int damage;
	cocos2d::Vec2 position;

	virtual bool collision(GameObject* obj) = 0;
};

struct AttackInfoCircle : public AttackInfo {
	int radius;

	bool collision(GameObject* obj) override;
};

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

	void applyDamage(Character* obj);
	void applyDamage(Sheep* obj);

	void clearToMobDamagerVector() {
		toMobDamageVector->clear();
	}
};

