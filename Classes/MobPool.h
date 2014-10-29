#pragma once

#include "cocos2d.h"
#include "Character.h"

class Sheep;

class MobPool : public cocos2d::Node {

private:
	cocos2d::Vec2 targetPos;
	cocos2d::Size targetSize;
public:
	MobPool();
	virtual ~MobPool();

	static MobPool* create();
	bool init() override;
	void update(float dt) override;

	void createSheep();

	void setTargetInfo(Character* obj) {
		targetPos = obj->getPosition();
		targetSize = obj->getContentSize();
	}
};