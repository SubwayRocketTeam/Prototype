#pragma once

#include "cocos2d.h"

class Sheep;
class Character;
class MobPool;

class GameScene : public cocos2d::Scene {

private:
	Character* character;
	MobPool* pool;
public:
	GameScene();
	virtual ~GameScene();

	bool init() override;

	void update(float dt) override;
	CREATE_FUNC(GameScene);
};