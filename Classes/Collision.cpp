#include <math.h>
#include "Collision.h"

bool Collision::collisionCircle(cocos2d::Vec2 pos1, float r1, cocos2d::Vec2 pos2, float r2) {
	pos2 = pos2 - pos1;
	pos1 = pos1 - pos1;

	if (sqrtf(pos2.x * pos2.x + pos2.y * pos2.y) <= (r1 + r2)) {
		return true;
	}
	return false;
}