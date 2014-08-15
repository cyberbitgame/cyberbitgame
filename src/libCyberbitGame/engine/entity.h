#include "weapon_melee.h"
#include "resistance.h"
#include "character.h"

#ifndef ENTITY_H
#define ENTITY_H

/**
 * Entity class. Define the entity parameters for the characters.
 */

class Entity {

private:
	Character entity_character;
	Weapon entity_weapon;
	Resistance entity_character;

public:
	Entity();
	~Entity();
};

#endif
