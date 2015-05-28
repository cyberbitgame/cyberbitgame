#include "libraries.h"
#include "frame.h"
#include "constants.h"
#include "player.h"
#include "./engine/music.h"

#ifndef GAME_H
#define GAME_H

class Game {
	int iAmRunning;
	SDL_Surface* icon;
	SDL_Surface* displayBlockMap;
	SDL_Surface* backgroundMap;
	SDL_Rect camera;
	bool gameKeyDownRun;
	int playerFaceDirection;
	std::vector< std::vector<int> > map;
	bool direction[2];
	bool running;
	enum _movement { L_MOVEMENT = 0,
					 R_MOVEMENT = 1 } movement;
	Player* gameplayer;
	Music* gamemusic;
	Uint32 redcolor;
	SDL_Surface* game_load_image(const char* imageFile, Uint32 colorKey);
	void game_load_map(const char* mapFile);
	void game_show_map();
	void game_event_handler();
	void game_logic_section();
	void game_render_section();

public:

	int FPS;
	SDL_Surface* screen;
	Game();
	~Game();
	void game_start();
	void game_load_characters();

};

#endif
