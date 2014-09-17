#ifndef MENU_H
#define MENU_H

#include "game.h"
#include "libraries.h"

class Game;

/**
 * @file menu.h
 * @brief Contains functions to render a menu into the game object
 */

class Menu {
    public:
/**
 * Public function to access the menu framework
 * @param Int a integer matching to a menu definition in constants.h
 * @param Game A game object to render menu into
 * @return Returns NO_ERROR if successful, error code if unsuccessful
 */
        static int menu_load(int menu_type, Game* game_obj);
};

/**
 * Public function to access the menu framework
 * @param Game A game object to render menu into
 * @return Returns NO_ERROR if successful, error code if unsuccessful
 */
int _main_menu(Game* game_obj);

/**
 * Public function to access the menu framework
 * @param Game a game object to render menu into
 * @return Returns NO_ERROR if successful, error code if unsuccessful
 */
int _pause_menu(Game* game_obj);

/**
 * Public function to access the menu framework
 * @param Game A game object to render menu into
 * @param char char pointer to use as title of menu
 * @param int Number of buttons to be used
 * @param char char array pointer of text to use for buttons
 * @return Returns key of label in label array when clicked
 */
int _load_menu(Game* game_obj, const char* menu_header, int btn_count, const char* btn_labels[]);

#endif
