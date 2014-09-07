#include "gameplay.h"
#include "../libCyberbitGame/cyberbitGame.h"

GamePlay::GamePlay()
{
	Game Cyberbit;
	Cyberbit.game_load_characters(); //This should populate globals' json_characters object
	Menu::menu_load(MAIN_MENU, &Cyberbit);

}

GamePlay::~GamePlay()
{
	std::cout<<"Game Over";
}
