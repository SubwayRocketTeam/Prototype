#include "GameScene.h"
#include "Sheep.h"
#include "AttackManager.h"
#include "Character.h"

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

	sheepList = new Vector<Sheep*>();

	createSheep();

	this->addChild(character);

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

	int eraseSheepCount = 0;
	auto it = sheepList->begin();
	while (it != sheepList->end()) {
		Sheep* obj = (*it);

		obj->setTargetPosition(character->getPosition());
		obj->setTargetSize(character->getContentSize());
		obj->update(dt);

		if (!obj->isAlive()) {
			this->removeChild(obj);
			it = sheepList->erase(it);
			eraseSheepCount++;
		}
		else {
			it++;
		}
	}

	for (int i = 0; i < eraseSheepCount * 2; i++) {
		this->createSheep();
	}
}

void GameScene::createSheep() {
	Sheep* sheep = Sheep::create("sheep.png");
	sheep->setPosition(rand()%800, rand()%480);
	sheepList->pushBack(sheep);

	this->addChild(sheep);
}