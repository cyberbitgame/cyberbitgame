#include "gameplay.h"

GamePlay::GamePlay() 
{
	Game Cyberbit;
	Cyberbit.game_start();

}

GamePlay::~GamePlay()
{
	std::cout<<"Game Over";
}
