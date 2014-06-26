AM_CPPFLAGS = -I$(top_srcdir)/src/libCyberbitGame
CFLAGS   = -g `sdl-config --cflags`
CXXFLAGS = -Wall -Wextra -g `sdl-config --cflags`
LDFLAGS  = `sdl-config --libs` \
           -lSDL_image -lSDL_ttf -lSDL_mixer -lm

lib_LTLIBRARIES = libCyberbitGame.la
bin_PROGRAMS = cyberbitGame

cyberbitGame_SOURCES = cyberbitGameplay/main.cpp cyberbitGameplay/gameplay.cpp
cyberbitGame_LDADD = libCyberbitGame.la
cyberbitGame_LDFLAGS = -lSDL -lSDL_ttf -lSDL_mixer

libCyberbitGame_la_SOURCES = libCyberbitGame/game.cpp \
			  				 libCyberbitGame/player.cpp 
