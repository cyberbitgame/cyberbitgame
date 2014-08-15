#ifndef CHARACTER_H
#define CHARACTER_H

class Character {

protected:

	std::string charcater_name;
	std::string charcater_nickname;
	char character_gender;
	int character_health;
	int character_stamina;

public:
	Character();
	~Character();

};
#endif
