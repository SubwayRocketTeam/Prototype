#pragma once

#include "cocos2d.h"

class Collision {
public:
	static bool collisionCircle(cocos2d::Vec2 pos1, float r1, cocos2d::Vec2 pos2, float r2);
};