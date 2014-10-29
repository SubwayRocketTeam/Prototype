#include "Character.h"
#include "AttackManager.h"
#include "Collision.h"

USING_NS_CC;

Character::Character() {
	speed = 500;
	maxhp = 100;
	hp = maxhp;
	damage = 10;
	range = 100;
}

Character::~Character() {

}

void Character::attack(float dt) {

}

void Character::move(float dt) {
	this->setPosition(this->getPosition() + direction.getNormalized() * speed * dt);
}

void Character::update(float dt) {
	GameObject::update(dt);

	AttackManager* manager = AttackManager::getInstance();
	manager->applyDamage(this);
}

bool Character::init() {
	return Sprite::init();
}

bool Character::initWithFile(char* filename) {

	if (!GameObject::initWithFile(filename)) {
		return false;
	}

	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(Character::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(Character::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(Character::onMouseDown, this);
	mouseListener->onMouseUp = CC_CALLBACK_1(Character::onMouseUp, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	this->setAnchorPoint(Vec2(0.5f, 0.5f));

	return true;
}

void Character::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* _event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_W) {
		direction.y = 1;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S) {
		direction.y = -1;
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_A) {
		direction.x = -1;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_D) {
		direction.x = 1;
	}

	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE) {
		AttackManager* attack = AttackManager::getInstance();
 		attack->attackFromUserToMob(this->getContentSize().width * 2, this->damage, this->getPosition());
	}
}

void Character::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* _event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_W) {
		direction.y = 0;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_A) {
		direction.x = 0;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S) {
		direction.y = 0;
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_D) {
		direction.x = 0;
	}
}

void Character::onMouseDown(Event* _event) {
	EventMouse* e = (EventMouse*)_event;
}

void Character::onMouseUp(Event* _event) {
	EventMouse* e = (EventMouse*)_event;
}