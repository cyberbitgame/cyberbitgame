#ifndef MENU_H
#define MENU_H

#include "game.h"

class Game;

class Menu {
    public:
        static void menu_load(int menu_type, Game* game_obj);
};

void _main_menu(Game* game_obj);
void _pause_menu(Game* game_obj);
int _load_menu(Game* game_obj, const char* menu_header, int btn_count, const char* btn_labels[]);

#endif
