#include "Sheep.h"
#include "AttackManager.h"
#include "Collision.h"

USING_NS_CC;

Sheep::Sheep() {
	speed = 50;
	maxhp = 25;
	hp = maxhp;
	damage = 5;
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
	AttackManager* attack = AttackManager::getInstance();
	attack->attackFromMobToUser(this->getContentSize().width * 2, this->damage, this->getPosition());
}

void Sheep::move(float dt) {
	this->setPosition(this->getPosition() + direction.getNormalized() * speed * dt);
}

void Sheep::update(float dt) {
	this->move(dt);

	AttackManager* manager = AttackManager::getInstance();
	for (AttackInfo* info : *(manager->getMobDamageVector())) {
		if (info->collision(this)) {
			this->hp -= info->damage;
			this->setOpacity(this->getOpacity() - 255 * info->damage / this->maxhp);
		}
	}

	if (Collision::collisionCircle(this->getPosition(), this->getContentSize().width / 2, targetPosition, targetSize.width / 2)) {
		attack(dt);
	}
}

void Sheep::randomSetDirection(float dt) {
	direction.x = (float)(rand() % 30000) / 10000 - 1;
	direction.y = (float)(rand() % 30000) / 10000 - 1;

	this->setRotation(CC_RADIANS_TO_DEGREES(atan(direction.x / direction.y)));
}
