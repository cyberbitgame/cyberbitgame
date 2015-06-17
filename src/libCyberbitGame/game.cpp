#include "game.h"
#include "cyberbitGame.h"
#include "globals.h"
#include "errors.h"
#include <iostream>
#include <fstream>

SDL_Rect Frame::frameCoordinate;

Game::Game()
{
	direction[L_MOVEMENT] = 0;
	direction[R_MOVEMENT] = 0;
	gameKeyDownRun = false;
	gameKeyDownPunch = false;
	iAmRunning = 0;
	iAmPunching = 0;
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
	Uint32 whiteColorKey = SDL_MapRGB(screen->format,0xff,0xff,0xff);
	backgroundMap = game_load_image("../data/images/bgmap.bmp", whiteColorKey);
	displayBlockMap = game_load_image("../data/images/pieces.bmp", whiteColorKey);
	icon = game_load_image("../data/images/icon.bmp",whiteColorKey);
	SDL_WM_SetIcon(icon, NULL);
	SDL_WM_SetCaption("cyberbitGame", NULL);
	camera.x = 0;
	Frame::frameCoordinate.x = 0;
	camera.y = 0;
	Frame::frameCoordinate.y = 0;
	camera.h = SCREEN_HEIGHT;
	Frame::frameCoordinate.h = SCREEN_HEIGHT;
	camera.w = SCREEN_WIDTH;
	Frame::frameCoordinate.w = SCREEN_HEIGHT;
	playerFaceDirection = R_MOVEMENT;
	redcolor = SDL_MapRGB(screen->format, 255, 0, 0);
	gameplayer = new Player(game_load_image("../data/images/standing/cyberbit/stand.bmp", whiteColorKey),
							game_load_image("../data/images/running/cyberbit/running.bmp", whiteColorKey),
							game_load_image("../data/images/attacking/cyberbit/punching.bmp", whiteColorKey),
							screen);
	gamemusic = new Music();
	gamemusic->music_play_music(BACKGROUND_MUSIC);
}

Game::~Game()
{
	SDL_FreeSurface(displayBlockMap);
	SDL_FreeSurface(backgroundMap);
	SDL_FreeSurface(icon);
	SDL_Quit();
}

void Game::game_event_handler()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT: running = false;
							break;

			case SDL_KEYDOWN: switch (event.key.keysym.sym) {
								case SDLK_LEFT: direction[L_MOVEMENT]=1;
												gameKeyDownRun = true;
												 break;
								case SDLK_RIGHT: direction[R_MOVEMENT]=1;
												gameKeyDownRun = true;
												 break;
								case SDLK_p: 
											 gameKeyDownPunch = true;
											break;
								case SDLK_k: gamemusic->music_play_chunk(KICK_CHUNK);
											break;
								//case SDLK_SPACE: for jump
								//case SDLK_S : for shoot
								default: break;
							  }
							  break;

			case SDL_KEYUP: switch (event.key.keysym.sym) {
								case SDLK_LEFT: direction[L_MOVEMENT]=0;
												gameKeyDownRun = false;
												break;
								case SDLK_RIGHT: direction[R_MOVEMENT]=0;
												gameKeyDownRun = false;
												 break;
                                case SDLK_ESCAPE: Menu::menu_load(PAUSE_MENU, this);
                                                  break;
								default: break;
							}
							break;
		}
	}
}

void Game::game_load_map(const char* mapFile)
{
	std::ifstream mapData(mapFile);
	int mapRowSize;
	int mapColumnSize;
	int mapCurrentBlock;
	if(!mapData.is_open()) {
		std::cout<<"Unable to load mapfile\n" << mapFile;
		exit(EXIT_FAILURE);
	}

	mapData >> mapColumnSize;
	mapData >> mapRowSize;
	for(int i=0;i<mapRowSize;i++) {
		std::vector<int> vec;
		for(int j=0;j<mapColumnSize;j++) {
			if(mapData.eof()) {
				std::cout<<"Map not defined properly\n";
				exit(EXIT_FAILURE);
			}
			mapData >> mapCurrentBlock;
			if( mapCurrentBlock >=-1 && mapCurrentBlock <=8) {
				vec.push_back(mapCurrentBlock);
			}
			else {
				vec.push_back(0);
			}
		}
		map.push_back(vec);
	}
	mapData.close();
}

void Game::game_show_map()
{

	for (int i=0; i<map.size(); i++) {
		for (int j=0; j<map[0].size(); j++) {
				if(map[i][j] != 0) {
				SDL_Rect blockPiece = {(map[i][j]-1)*TILE_SIZE, 0, TILE_SIZE, TILE_SIZE};
				SDL_Rect showPiece = {(j*TILE_SIZE)-Frame::frameCoordinate.x, i*TILE_SIZE};
				SDL_BlitSurface(displayBlockMap, &blockPiece, screen, &showPiece);
			}

		}

	}

}

void Game::game_logic_section()
{
	if(gameKeyDownPunch == true) {
		iAmPunching++;
		switch (iAmPunching) {
			case 1: gamemusic->music_play_chunk(PUNCH_CHUNK);
					break;
			case 19: iAmPunching = 0;
					 gameKeyDownPunch = false;
					 break;
		}
	}
	if(direction[R_MOVEMENT]) {
		camera.x += SPEED;
		playerFaceDirection = R_MOVEMENT;
		Frame::frameCoordinate.x += SPEED;
		if (gameKeyDownRun == true) {
			if (iAmRunning > 42)
				iAmRunning = 0;
			iAmRunning++;
		}
		if(camera.x >= (BGMAPX - SCREEN_WIDTH)) {
			camera.x = 0;
		}
	}
	else if(direction[L_MOVEMENT]) {
		camera.x -= SPEED;
		playerFaceDirection = L_MOVEMENT;
		Frame::frameCoordinate.x -= SPEED;
		if (gameKeyDownRun == true) {
			if (iAmRunning > 42)
				iAmRunning = 0;
			iAmRunning++;
		}
		if(camera.x <= 0) {
			camera.x = BGMAPX - SCREEN_WIDTH;
		}
	}

	gameplayer->player_move(map);
}

void Game::game_render_section()
{
	if (SDL_BlitSurface(backgroundMap, &camera, screen, NULL) != 0) {
		std::cout<<"Blit Surface Failed: "<<SDL_GetError();
		std::cout<<std::endl;
		exit(EXIT_FAILURE);
	}
	game_show_map();
	gameplayer->player_healthBarShow(screen, redcolor);
	gameplayer->player_show(screen,
							playerFaceDirection,
							iAmRunning,
							gameKeyDownRun,
							iAmPunching,
							gameKeyDownPunch);
	SDL_Flip(screen);
}


void Game::game_start()
{
    //Setup gameplayer stats
	gameplayer->player_load_defaults(0);

	const int FPS=30;
	Uint32 start;
	running = true;
	game_load_map("../data/maps/foregroundmap.map");
	while(running) {
		start = SDL_GetTicks();
		game_event_handler();
		game_logic_section();
		game_render_section();
		SDL_Flip(screen);
		if(1000/FPS > SDL_GetTicks()-start)
			SDL_Delay (1000/FPS-(SDL_GetTicks()-start));
	}


}

SDL_Surface* Game::game_load_image(const char* imageFile, Uint32 colorKey)
{
	SDL_Surface* imageLoad = SDL_LoadBMP(imageFile);
	if (imageLoad == NULL) {
		std::cout<<"Image Loading Failed: "<<SDL_GetError();
		std::cout<<std::endl;
		exit(EXIT_FAILURE);
	}
	SDL_Surface* imageFormat = SDL_DisplayFormat(imageLoad);
	if (imageFormat == NULL) {
		std::cout<<"Unable to set display format: "<<SDL_GetError();
		std::cout<<std::endl;
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(imageLoad);
	if (SDL_SetColorKey(imageFormat, SDL_SRCCOLORKEY, colorKey) != 0) {
		std::cout<<"Unable to set colorKey: "<<SDL_GetError();
		std::cout<<std::endl;
		exit(EXIT_FAILURE);
	}
	return imageFormat;
}

void Game::game_load_characters()
{
    std::ifstream file("../data/characters.json");
    if( !file.good() )
        exit(MISSING_CHARACTER_FILE);
    std::string character_string((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
    Json::Reader reader;
    if(!reader.parse(character_string, json_characters, false))
    {
        if(DEV){std::cout<<"Fatal error: Parse json_characters failed."<<'\n';}
        exit(CANNOT_PARSE_CHARACTER_FILE);
    }
}
