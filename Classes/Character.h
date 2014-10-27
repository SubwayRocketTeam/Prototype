#pragma once

#include "GameObject.h"
#include "CustomPlatformMacros.h"
#include "cocos2d.h"

class Character : public GameObject {
private:
	cocos2d::Sprite* rangeSprite;
public:
	Character();
	~Character();

	bool init() override;
	bool initWithFile(char* filename) override;

	void attack(float dt) override;
	void move(float dt) override;

	void update(float dt) override;

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* _event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* _event);

	void onMouseDown(cocos2d::Event* _event);
	void onMouseUp(cocos2d::Event* _event);

	CREATE_SPRITE_FUNC(Character);
};