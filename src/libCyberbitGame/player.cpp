#include "player.h"
#include "globals.h"

extern Json::Value json_characters;

Player::Player(SDL_Surface* characterImage, SDL_Surface* screen)
{
	playerImage = characterImage;
	playerFrame.x = POS_START;
	playerFrame.y = POS_GROUND;
	playerFrame.h = TILE_SIZE;
	playerFrame.w = TILE_SIZE;
	playerFaceFwdDirection.x = 0;
	playerFaceFwdDirection.y = 0;
	playerFaceFwdDirection.h = TILE_SIZE;
	playerFaceFwdDirection.w = TILE_SIZE;
	playerFaceBwdDirection.x = TILE_SIZE;
	playerFaceBwdDirection.y = 0;
	playerFaceBwdDirection.h = TILE_SIZE;
	playerFaceBwdDirection.w = TILE_SIZE;
	playerXVelocity = 0;
	playerYVelocity = 0;
	onGround = 0;
	playerHealth = MAX_HEALTH;
	color = SDL_MapRGB(screen->format, 255, 0, 0);
	player_healthBarShow(screen, color);
	// for loop to set the animations
}

Player::~Player()
{
	SDL_FreeSurface(playerImage);
}

float Player::player_healthBarUpdate()
{
	if (playerHealth > MAX_HEALTH) {
		exit(MAX_HEALTH_REACHED);
	}
	return playerHealth;
}

int Player::player_healthBarShow(SDL_Surface* screen, Uint32 color)
{
	healthBar.w = player_healthBarUpdate();
	healthBar.h = TILE_SIZE/5;
	healthBar.x = TILE_SIZE/4;
	healthBar.y = TILE_SIZE/4;
	SDL_FillRect(screen, &healthBar, color);
	return EXIT_SUCCESS;
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

void Player::player_show(SDL_Surface* screen, int playerFaceDirection)
{
	if (playerFaceDirection == 1) {
		SDL_BlitSurface(playerImage, &playerFaceFwdDirection, screen, &playerFrame);
	}
	else {
		SDL_BlitSurface(playerImage, &playerFaceBwdDirection, screen, &playerFrame);
	}
}

void Player::player_move(const std::vector<std::vector <int> >& map)
{
	bool nc=0;
	for (int i=0; i<map.size(); i++) {
		for (int j=0; j<map[0].size(); j++) {
			if (map[i][j] == 0) {
				continue;
			}
			SDL_Rect showPiece = {(j*TILE_SIZE)-Frame::frameCoordinate.x, i*TILE_SIZE, TILE_SIZE, TILE_SIZE};
			if(physics_collision(&playerFrame, &showPiece)) {
				nc = 1;
				if(showPiece.y >= playerFrame.y + playerFrame.h - 5) {
					onGround = 1;
					playerYVelocity = 0;
				}
				else if (showPiece.y+showPiece.h <= playerFrame.y) {
					playerFrame.x++;
					playerYVelocity = 0;
				}
				if (playerFrame.x+playerFrame.w >= showPiece.x && playerFrame.y+playerFrame.h >= showPiece.y && playerFrame.x+playerFrame.w<= showPiece.x+20) {
					playerXVelocity = 0;
					playerFrame.x--;
				} else if (playerFrame.x <= showPiece.x+showPiece.w && playerFrame.y+playerFrame.h >= showPiece.y) {
					playerXVelocity = 0;
					playerFrame.x++;
				}
			}
		}
	}

	if(!nc) {
		playerYVelocity = 5;
	}

	playerFrame.x+=playerXVelocity;
	playerFrame.y+=playerYVelocity;
}

void Player::player_load_defaults(int character_id)
{
    //Make sure the id exists
    if( character_id < 0 || character_id >= (int)json_characters.size() ) {
        if(DEV){std::cout<<"character "<<character_id<<" does not exist."<<'\n';}
        return;
    }

    if( json_characters[character_id]["Name"].asString().empty() ) {
        if(DEV){std::cout<<"character "<<character_id<<" missing \"Name\""<<'\n';}
        return;
    }
    if(!json_characters[character_id]["Health"].isInt()) {
        if(DEV){std::cout<<"character "<<character_id<<" has invalid health"<<'\n';}
        return;
    }
    if(!json_characters[character_id]["Stamina"].isInt()) {
        if(DEV){std::cout<<"character "<<character_id<<" has invalid stamina"<<'\n';}
        return;
    }

    /* //Load stats into self
    this.name = json_characters[character_id]["Name"].asString();
    this.health = json_characters[character_id]["Health"].asInt();
    this.stamina = json_characters[character_id]["Stamina"].asInt();
    */
    return;
}
