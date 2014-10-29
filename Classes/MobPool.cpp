#include "MobPool.h"
#include "Sheep.h"
#include "AttackManager.h"

using namespace cocos2d;

MobPool::MobPool() {
	
}

MobPool::~MobPool() {

}

MobPool * MobPool::create()
{
	MobPool * ret = new (std::nothrow) MobPool();
	if (ret && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

bool MobPool::init() {
	if (!Node::init()) {
		return false;
	}

	sheepList = new Vector<Sheep*>();

	this->setAnchorPoint(Vec2(0, 0));
	this->setPosition(Vec2(0, 0));

	return true;
}

void MobPool::update(float dt) {
	int eraseSheepCount = 0;
	auto it = sheepList->begin();
	while (it != sheepList->end()) {
		Sheep* obj = (*it);

		obj->setTargetPosition(targetPos);
		obj->setTargetSize(targetSize);
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

	AttackManager::getInstance()->clearToMobDamagerVector();
}

void MobPool::createSheep() {
	Sheep* sheep = Sheep::create("sheep.png");
	sheep->setPosition(rand() % 800, rand() % 480);
	sheepList->pushBack(sheep);

	this->addChild(sheep);
}