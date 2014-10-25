#include "AttackManager.h"

USING_NS_CC;

AttackManager* AttackManager::instance = nullptr;

AttackManager::AttackManager() {
	toMobDamageVector = new std::vector<AttackInfoCircle>();
	toUserDamageVector = new std::vector<AttackInfoCircle>();
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

	AttackInfoCircle info;
	info.position = position;
	info.radius = range;
	info.damage = damage;

	toMobDamageVector->push_back(info);
}

void AttackManager::attackFromMobToUser(int range, int damage, Vec2 position) {

	AttackInfoCircle info;
	info.position = position;
	info.radius = range;
	info.damage = damage;

	toUserDamageVector->push_back(info);
}

void AttackManager::clear() {
	toMobDamageVector->clear();
	//toUserDamageVector->clear();
}