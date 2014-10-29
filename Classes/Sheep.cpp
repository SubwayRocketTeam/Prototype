#include "Sheep.h"
#include "AttackManager.h"
#include "Collision.h"

USING_NS_CC;

Sheep::Sheep() {
	speed = 50;
	maxhp = 25;
	hp = maxhp;
	damage = 1;
}

Sheep::~Sheep() {

}

bool Sheep::init() {
	return GameObject::init();
}

bool Sheep::initWithFile(char* filename) {
	if (!GameObject::initWithFile(filename)) {
		return false;
	}

	this->schedule(schedule_selector(Sheep::randomSetDirection), 1.0f);
	randomSetDirection(0);

	return true;
}

void Sheep::attack(float dt) {
	AttackManager* manager = AttackManager::getInstance();
	manager->attackFromMobToUser(this->getContentSize().width * 2, this->damage, this->getPosition());
}

void Sheep::move(float dt) {
	this->setPosition(this->getPosition() + direction.getNormalized() * speed * dt);
}

void Sheep::update(float dt) {
	GameObject::update(dt);

	AttackManager* manager = AttackManager::getInstance();
	manager->applyDamage(this);

	if (Collision::collisionCircle(this->getPosition(), this->getContentSize().width / 2, targetPosition, targetSize.width / 2)) {
		attack(dt);
	}
}

void Sheep::randomSetDirection(float dt) {
	direction.x = (float)(rand() % 30000) / 10000 - 1;
	direction.y = (float)(rand() % 30000) / 10000 - 1;

	this->setRotation(CC_RADIANS_TO_DEGREES(atan(direction.x / direction.y)));
}
