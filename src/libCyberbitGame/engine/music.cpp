#include "music.h"

Music::Music()
{

	if(Mix_OpenAudio(22050,AUDIO_S16SYS,2,640) == -1) {
    	exit(UNABLE_TO_OPEN_AUDIO_SDL);
	}
	std::cout<<"Game Constructor";

	bgmusic = music_load_music("../data/music/heroTheme_music.mp3");
	sounds = music_load_chunk("../data/music/punchSound_chunk.wav");
}

Music::~Music()
{
	Mix_FreeChunk(sounds);
	Mix_FreeMusic(bgmusic);
	Mix_CloseAudio();
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

int Music::music_play_music(int music_track)
{
	switch(music_track) {
 		case BACKGROUND_MUSIC: {
 									if(Mix_PlayMusic(bgmusic, ONE_TIME)==-1) {
    									exit(UNABLE_TO_PLAY_MUSIC);
    								}
								}
								break;
		case HERO_MUSIC: {

						 }
						 break;

	}
}

int Music::music_play_chunk(int chunk_track)
{

	switch(chunk_track) {
		case PUNCH_CHUNK: {
								if(Mix_PlayChannel(FIRST_FREE_UNRESERVED_CHANNEL, sounds, ONCE) == -1) {
							    	exit(UNABLE_TO_PLAY_CHUNK);
						  		}
						  }
						  break;


	}
}

