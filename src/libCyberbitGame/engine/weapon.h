#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
protected:

	int weapon_melee_blade;
	int weapon_melee_fire;
	int weapon_melee_water;
	int weapon_melee_impact;
	int weapon_melee_em;
	int weapon_melee_pierce;
	std::string weapon_melee_name;
	int weapon_shoot_blade;
	int weapon_shoot_fire;
	int weapon_shoot_water;
	int weapon_shoot_impact;
	int weapon_shoot_em;
	int weapon_shoot_pierce;
	std::string weapon_shoot_name;

public:
	Weapon();
	~Weapon();

};
#endif
