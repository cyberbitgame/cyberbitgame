#include "../cyberbitGame.h"

#ifndef MUSIC_H
#define MUSIC_H

class Music {

	Mix_Music* bgmusic;
	Mix_Chunk *sounds;
	Mix_Music* music_load_music(const char* music_file);
	Mix_Chunk* music_load_chunk(const char* chunk_file);

public:
	Music();
	~Music();
	int music_play_music(int music_track);
	int music_play_chunk(int chunk_track);

};

#endif