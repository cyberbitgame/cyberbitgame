#include "libraries.h"
#include "game.h"
#include "menu.h"

void Menu::menu_load(int menu_type, Game* game_obj) {
    switch(menu_type) {
        case MAIN_MENU:
            if(DEV){std::cout<<"Rendering main menu"<<'\n';}
            _main_menu(game_obj);
            break;
        case PAUSE_MENU:
            _pause_menu(game_obj);
            break;
    }
    return;
}

void _main_menu(Game* game_obj) {
    const int btn_count = 3;
    const char* btn_labels[btn_count] = {"Play","Character Select","Exit"};
    const char* menu_header = "Main  Menu";
    const int PLAY=0,CHARACTER_SELECT=1,EXIT=2;
    int btn_clicked = _load_menu( game_obj, menu_header, btn_count, btn_labels );
    switch(btn_clicked) {
        case PLAY:
            if(DEV){std::cout<<"starting game"<<'\n';}
            game_obj->game_start();
        break;
        case CHARACTER_SELECT:
            //Character select
        break;
        case EXIT:
            //Exit
        break;
    }
    return;
}

void _pause_menu(Game* game_obj) {
    const int btn_count = 2;
    const char* btn_labels[btn_count] = {"Resume","Exit"};
    const char* menu_header = "Paused";
    const int RESUME=0,EXIT=1;
    int btn_clicked = _load_menu( game_obj, menu_header, btn_count, btn_labels );
    switch(btn_clicked) {
        case RESUME:
            if(DEV){std::cout<<"resuming game"<<'\n';}
        break;
        case EXIT:
            //Exit
            exit(0); //Fix this up later
        break;
    }
    return;
}

int _load_menu(Game* game_obj, const char* menu_header, int btn_count, const char* btn_labels[]) {
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("../data/font/font.ttf", 32);
    SDL_Surface* header;
    SDL_Surface* buttons[btn_count];
    bool selected[btn_count];
    for(int a=0;a<btn_count;a++)
        selected[a]=0;
    SDL_Color btn_colors[2] = {{255,255,255},{255,0,0}};

    int total_btn_height = 0;

    header = TTF_RenderText_Solid(font, menu_header, btn_colors[0]);

    for(int a=0;a<btn_count;a++) {
        buttons[a] = TTF_RenderText_Solid(font, btn_labels[a], btn_colors[0]);
        total_btn_height += buttons[a]->clip_rect.h;
    }

    SDL_Rect header_pos;
    header_pos.x = game_obj->screen->clip_rect.w/2 - header->clip_rect.w/2;
    header_pos.y = 20;

    SDL_Rect btn_pos[btn_count];

    int tmp_btn_height = total_btn_height;
    for(int a=0;a<btn_count;a++) {
        btn_pos[a].x = game_obj->screen->clip_rect.w/2 - buttons[a]->clip_rect.w/2;
        btn_pos[a].y = game_obj->screen->clip_rect.h/2 - tmp_btn_height;
        tmp_btn_height -= buttons[a]->clip_rect.h;
    }

    int x,y;

    SDL_FillRect(game_obj->screen, &game_obj->screen->clip_rect, SDL_MapRGB(game_obj->screen->format,0x00,0x00,0x00));

    SDL_Event event;
    Uint32 time;
    while(1) {
        time = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    for(int a=0;a<btn_count;a++) {
                        SDL_FreeSurface(buttons[a]);
                    }
                    return 0;
                break;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;
                    for(int a=0;a<btn_count;a++) {

                        //If mouse is over label
                        if( x > btn_pos[a].x && x <= btn_pos[a].x+btn_pos[a].w && y >= btn_pos[a].y && y <= btn_pos[a].y+btn_pos[a].h ) {
                            if(!selected[a]) {
                                selected[a] = true;
                                SDL_FreeSurface(buttons[a]);
                                buttons[a] = TTF_RenderText_Solid(font, btn_labels[a], btn_colors[1]);
                            }
                        }
                        else {
                            selected[a] = false;
                            SDL_FreeSurface(buttons[a]);
                            buttons[a] = TTF_RenderText_Solid(font, btn_labels[a], btn_colors[0]);
                        }
                    }
                break;
                case SDL_MOUSEBUTTONDOWN:
                    x = event.button.x;
                    y = event.button.y;
                    for(int a=0;a<btn_count;a++) {

                        //If mouse clicked over label
                        if( x > btn_pos[a].x && x <= btn_pos[a].x+btn_pos[a].w && y >= btn_pos[a].y && y <= btn_pos[a].y+btn_pos[a].h ) {
                            for(int b=0;b<btn_count;b++)
                                SDL_FreeSurface(buttons[b]);
                            return a;
                        }
                    }
                break;
            }
        }

        SDL_BlitSurface(header, NULL, game_obj->screen, &header_pos);

        for(int a=0;a<btn_count;a++) {
            SDL_BlitSurface(buttons[a], NULL, game_obj->screen, &btn_pos[a]);
        }
        SDL_Flip(game_obj->screen);
        if( (Uint32)(1000/game_obj->FPS) > (SDL_GetTicks()-time) )
            SDL_Delay(1000/game_obj->FPS-(SDL_GetTicks()-time));
    }
    return 0;
}
