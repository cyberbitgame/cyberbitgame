#include "physics.h"

bool Physics::physics_collision(SDL_Rect* object1, SDL_Rect* object2)
{
	if (object1->y >= (object2->y + object2->h))
		return 0;
	if (object1->x >= (object2->x + object2->w))
		return 0;
	if ((object1->y + object1->h) <= object2->y )
		return 0;
	if ((object1->x + object1->w) <= object2->x )
		return 0;
	return 1;
}