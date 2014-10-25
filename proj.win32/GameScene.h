#pragma once

#include "cocos2d.h"

class Sheep;
class Character;

class GameScene : public cocos2d::Scene {

private:
	Character* character;
	cocos2d::Vector<Sheep*>* sheepList;
public:
	GameScene();
	~GameScene();

	bool init() override;

	void update(float dt) override;

	void createSheep();

	CREATE_FUNC(GameScene);
};