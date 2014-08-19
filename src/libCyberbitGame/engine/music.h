#include "../cyberbitGame.h"

#ifndef MUSIC_H
#define MUSIC_H

class Music {

	Mix_Music* bgMusic;
	Mix_Chunk *sounds;
	Mix_Music* music_load_music(const char* music_file);
	Mix_Chunk* music_load_chunk(const char* chunk_file);

public:
	Music();
	~Music();

};

#endif