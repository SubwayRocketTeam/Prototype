#include "GameObject.h"

GameObject::GameObject() :
 hp(0), damage(0), speed(0), direction(cocos2d::Vec2(0, 0)), position(cocos2d::Vec2(0, 0)) {

}

GameObject::~GameObject() {

}

bool GameObject::init() {
	if (!Sprite::init()) {
		return false;
	}

	return true;
}

bool GameObject::initWithFile(char* filename) {
	if (!Sprite::initWithFile(filename)) {
		return false;
	}

	return true;
}