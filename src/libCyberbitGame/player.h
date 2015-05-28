#include "libraries.h"
#include "constants.h"
#include "frame.h"
#include "physics.h"
#include "cyberbitGame.h"
#include "errors.h"
#include "globals.h"

#ifndef PLAYER_H
#define PLAYER_H

typedef enum _graph { XAXIS = 1,
					  YAXIS = 2
} graph;

class Player : public Physics {
	SDL_Rect playerFrame;
	SDL_Rect playerFaceFwdDirection;
	SDL_Rect playerFaceBwdDirection;
	SDL_Rect healthBar;
	SDL_Surface* playerImage;
	int playerXVelocity;
	int playerYVelocity;
	bool playerRunning;
	int frameCount;
	bool onGround;
	float playerHealth;
	Uint32 color;
	SDL_Surface* playerRunAnimation;
	SDL_Rect playerRunningFwdFrame[16];
	SDL_Rect playerRunningBwdFrame[16];
public:
	Player(SDL_Surface* characterImage, SDL_Surface* characterRunAnimation, SDL_Surface* screen);
	~Player();

/**
 * player_healthBarUpdate function to update the health bar of player
 * @return the current health of the player
 */
	float player_healthBarUpdate();

/**
 * player_healthShow function to display the health bar of player
 * @param screen is the default background, where all elements are loaded
 * @param color provides the color of bar
 * @return success if bar is loaded
 */

	int player_healthBarShow(SDL_Surface* screen, Uint32 color);

	SDL_Rect* player_getPosition();
	void player_setVelocity(int velocity, graph axis);
	int player_getVelocity(graph axis);
	void player_move(const std::vector<std::vector <int> >& map);
	void player_show(SDL_Surface* screen, int playerFaceDirection, int iAmRunning, int playerRunning);
	void player_load_defaults(int character_id);
};

#endif
