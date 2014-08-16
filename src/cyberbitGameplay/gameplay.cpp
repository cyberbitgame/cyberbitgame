#include "gameplay.h"

GamePlay::GamePlay()
{
	Game Cyberbit;
	Cyberbit.game_load_characters(); //This should populate globals' json_characters object
	Cyberbit.game_start();

}

GamePlay::~GamePlay()
{
	std::cout<<"Game Over";
}
