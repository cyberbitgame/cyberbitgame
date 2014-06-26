#include "player.h"

Player::Player(SDL_Surface* characterImage)
{
	playerImage = characterImage;
	playerFrame.x = 0;
	playerFrame.y = 0;
	playerFrame.h = TILE_SIZE;
	playerFrame.w = TILE_SIZE;
	playerXVelocity = 0;
	playerYVelocity = 0;
	// for loop to set the animations
}

Player::~Player()
{
	SDL_FreeSurface(playerImage);
}

SDL_Rect* Player::player_getPosition()
{
	return &playerFrame;
}

void Player::player_setVelocity(int velocity, graph axis)
{
	switch(axis) {
		case XAXIS: playerXVelocity = velocity;
				    break;
		case YAXIS: playerYVelocity = velocity;
				    break;
		default: std::cout<<"Undefined player axis provided in Player class, Player::player_setVelocity()\n";
				 exit(EXIT_FAILURE);
	}
}

int Player::player_getVelocity(graph axis)
{
	switch(axis) {
		case XAXIS: return playerXVelocity;
		case YAXIS: return playerYVelocity;
		default: std::cout<<"Undefined player axis provided in Player class, Player::player_getVelocity()\n";
				 exit(EXIT_FAILURE);
	}
}

void Player::player_show(SDL_Surface* screen)
{
	SDL_BlitSurface(playerImage, NULL, screen, &playerFrame);
}

void Player::player_move(const std::vector<std::vector <int> >& map)
{
	playerFrame.x+=playerXVelocity;
	playerFrame.y+=playerYVelocity;


}