#pragma once

#include "cocos2d.h"

// Sheep, Character ������ �θ�Ŭ����
class GameObject : public cocos2d::Sprite {

protected:
	int maxhp;
	int hp;
	int damage;
	int range;
	float speed;
	cocos2d::Vec2 direction;
	cocos2d::Vec2 position;
public:
	GameObject();
	virtual ~GameObject();

	virtual bool init();
	virtual bool initWithFile(char* filename);

	virtual void attack(float dt) = 0;
	virtual void move(float dt) = 0;

	virtual void update(float dt);

	bool isAlive() {
		return hp > 0;
	}

	void sufferDamage(int damage) {
		hp -= damage;
	}
};