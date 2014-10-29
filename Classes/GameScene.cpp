#include "GameScene.h"
#include "Sheep.h"
#include "AttackManager.h"
#include "Character.h"
#include "MobPool.h"

USING_NS_CC;

GameScene::GameScene() {

}

GameScene::~GameScene() {

}

bool GameScene::init() {

	if (!Scene::init()) {
		return false;
	}

	srand((unsigned)time(NULL));

	this->scheduleUpdate();

	character = Character::create("red.png");
	character->setPosition(100, 100);

	pool = MobPool::create();
	pool->createSheep();

	this->addChild(character);
	this->addChild(pool);

	return true;
}

void GameScene::update(float dt) {
	if (!character->isAlive()) {
		this->removeChild(character);
		Director::getInstance()->end();
		return;
	}
	else {
		character->update(dt);
	}

	pool->update(dt);
	pool->setTargetInfo(character);
}