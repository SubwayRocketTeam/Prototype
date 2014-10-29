#include "AttackManager.h"
#include "Collision.h"
#include "GameObject.h"
#include "Character.h"
#include "Sheep.h"

USING_NS_CC;

AttackManager* AttackManager::instance = nullptr;

AttackManager::AttackManager() {
	toMobDamageVector = new std::vector<AttackInfo*>();
	toUserDamageVector = new std::vector<AttackInfo*>();
}

AttackManager::~AttackManager() {
	delete toUserDamageVector;
	delete toMobDamageVector;
}

AttackManager* AttackManager::getInstance() {
	if (!instance) {
		instance = new AttackManager();
	}

	return instance;
}

void AttackManager::attackFromUserToMob(int range, int damage, Vec2 position) {

	AttackInfoCircle* info = new AttackInfoCircle();
	info->position = position;
	info->radius = range;
	info->damage = damage;

	toMobDamageVector->push_back(info);
}

void AttackManager::attackFromMobToUser(int range, int damage, Vec2 position) {

	AttackInfoCircle* info = new AttackInfoCircle();
	info->position = position;
	info->radius = range;
	info->damage = damage;

	toUserDamageVector->push_back(info);
}

bool AttackInfoCircle::collision(GameObject* obj) {
	return Collision::collisionCircle(obj->getPosition(), obj->getContentSize().width / 2, this->position, this->radius);
}

void AttackManager::applyDamage(Character* obj) {
	for (AttackInfo* info : *toUserDamageVector) {
		if (info->collision(obj)) {
			obj->sufferDamage(info->damage);
		}
	}
	toUserDamageVector->clear();
}

void AttackManager::applyDamage(Sheep* obj) {
	for (AttackInfo* info : *toMobDamageVector) {
		if (info->collision(obj)) {
			obj->sufferDamage(info->damage);
		}
	}
}