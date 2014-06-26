#include "libraries.h"
#include "constants.h"
#include "frame.h"
#include "physics.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef enum _graph { XAXIS = 1,
				   YAXIS = 2
} graph;

class Player:Physics {
	SDL_Rect playerFrame;
	SDL_Surface* playerImage;
	int playerXVelocity;
	int playerYVelocity;
	// initialize an array that contain all the frame animation of character
public:
	Player(SDL_Surface* characterImage);
	~Player();
	SDL_Rect* player_getPosition();
	void player_setVelocity(int velocity, graph axis);
	int player_getVelocity(graph axis);
	void player_move(const std::vector<std::vector <int> >& map);
	void player_show(SDL_Surface* screen);
};

#endif
