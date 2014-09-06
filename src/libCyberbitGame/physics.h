#include "libraries.h"
#include "cyberbitGame.h"

#ifndef PHYSICS_H
#define PHYSICS_H

/**
 * Physics class. This class is used for describing the physics of the game
 * like collision detection. gravity and other parameters.
 */

class Physics {
protected:
/**
 * physics_collision function to check whether the collision occured or not
 * @param an SDL_Rect structure for object one
 * @param an SDL_Rect structure for other object
 * @return True, if collision occured, else False
 */
	bool physics_collision(SDL_Rect* object1, SDL_Rect* object2);

public:
		int physics_add(int x, int y);
};
#endif
