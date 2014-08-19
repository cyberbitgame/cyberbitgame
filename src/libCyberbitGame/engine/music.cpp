#include "music.h"

Music::Music()
{

	if(Mix_OpenAudio(22050,AUDIO_S16SYS,2,640) == -1) {
    	exit(UNABLE_TO_OPEN_AUDIO_SDL);
	}
	std::cout<<"Game Constructor";

	bgMusic = music_load_music("../data/music/aria.mp3");
	sounds = music_load_chunk("../data/music/start.wav");

}

Music::~Music()
{
	Mix_FreeChunk(sounds);
	Mix_FreeMusic(bgMusic);
}

Mix_Music* Music::music_load_music(const char* music_file)
{
	Mix_Music* audio_music;
	audio_music = Mix_LoadMUS(music_file);
	if(!audio_music) {
		exit(UNABLE_TO_LOAD_MUSIC_FILE);
	}
	return audio_music;

}

Mix_Chunk* Music::music_load_chunk(const char* chunk_file)
{
	Mix_Chunk* audio_chunk;
	audio_chunk = Mix_LoadWAV(chunk_file);
	if(!audio_chunk) {
		exit(UNABLE_TO_LOAD_CHUNK_FILE);
	}
	return audio_chunk;

}

