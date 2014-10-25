#pragma once

#include "CustomPlatformMacros.h"
#include "GameObject.h"

class Sheep : public GameObject {
private:
	cocos2d::Vec2 targetPosition;
	cocos2d::Size targetSize;
public:
	Sheep();
	~Sheep();

	bool init() override;
	bool initWithFile(char* filename) override;

	void attack(float dt) override;
	void move(float dt) override;

	void update(float dt) override;

	void randomSetDirection(float dt);

	void setTargetPosition(cocos2d::Vec2 userPosition) {
		targetPosition = userPosition;
	};

	void setTargetSize(cocos2d::Size userSize) {
		targetSize = userSize;
	}

	CREATE_SPRITE_FUNC(Sheep);
};