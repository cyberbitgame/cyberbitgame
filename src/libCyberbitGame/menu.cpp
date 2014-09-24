#include "menu.h"

int Menu::menu_load(int menu_type, Game* game_obj)
{
    switch(menu_type) {
        case MAIN_MENU:
            if(DEV){std::cout<<"Rendering main menu"<<'\n';}
            if( _main_menu(game_obj) != 0 )
                return UNABLE_TO_RENDER_MAIN_MENU; //Return error
            break;
        case PAUSE_MENU:
            if( _pause_menu(game_obj) != 0 )
                return UNABLE_TO_RENDER_PAUSE_MENU; //Return error
            break;
        default:
            return UNKNOWN_MENU_TYPE; //Return error
            break;
    }
    return NO_ERROR; //Return successful
}

int _main_menu(Game* game_obj)
{
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
        default:
            return UNKNOWN_BUTTON_CLICK;
        break;
    }
    return NO_ERROR; //Return successful
}

int _pause_menu(Game* game_obj)
{
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
        default:
            return UNKNOWN_BUTTON_CLICK;
        break;
    }
    return NO_ERROR;
}

int _load_menu(Game* game_obj, const char* menu_header, int btn_count, const char* btn_labels[])
{
    if( TTF_Init() != 0)
        return UNABLE_TO_INITIALIZE_TTF;

    const char* font_path = "../data/font/font.ttf";

    //Check if font file exists
    std::ifstream file(font_path);
    if( !file.good() )
        exit(MISSING_FONT_FILE);

    TTF_Font* font = TTF_OpenFont(font_path, 32);
    SDL_Surface* header;
    SDL_Surface* buttons[btn_count];
    bool selected[btn_count];
    SDL_Color btn_colors[2] = {{255,255,255},{255,0,0}};
    int total_btn_height = 0;
    header = TTF_RenderText_Solid(font, menu_header, btn_colors[0]);
    SDL_Rect header_pos;
    header_pos.x = game_obj->screen->clip_rect.w/2 - header->clip_rect.w/2;
    header_pos.y = 20;
    SDL_Rect btn_pos[btn_count];
    int tmp_btn_height = total_btn_height;
    int x,y;
    SDL_Event event;
    Uint32 time;

    for(int button=0;button<btn_count;button++)
        selected[button]=0;

    for(int button=0;button<btn_count;button++) {
        buttons[button] = TTF_RenderText_Solid(font, btn_labels[button], btn_colors[0]);
        total_btn_height += buttons[button]->clip_rect.h;
    }

    for(int button=0;button<btn_count;button++) {
        btn_pos[button].x = game_obj->screen->clip_rect.w/2 - buttons[button]->clip_rect.w/2;
        btn_pos[button].y = game_obj->screen->clip_rect.h/2 - tmp_btn_height;
        tmp_btn_height -= buttons[button]->clip_rect.h;
    }

    SDL_FillRect(game_obj->screen, &game_obj->screen->clip_rect, SDL_MapRGB(game_obj->screen->format,0x00,0x00,0x00));

    while(FOREVER) {
        time = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    for(int button=0;button<btn_count;button++) {
                        SDL_FreeSurface(buttons[button]);
                    }
                    return 0;
                break;
                case SDL_MOUSEMOTION:
                    x = event.motion.x;
                    y = event.motion.y;
                    for(int button=0;button<btn_count;button++) {

                        //If mouse is over label
                        if( x > btn_pos[button].x && x <= btn_pos[button].x+btn_pos[button].w && y >= btn_pos[button].y && y <= btn_pos[button].y+btn_pos[button].h ) {
                            if(!selected[button]) {
                                selected[button] = true;
                                SDL_FreeSurface(buttons[button]);
                                buttons[button] = TTF_RenderText_Solid(font, btn_labels[button], btn_colors[1]);
                            }
                        }
                        else {
                            selected[button] = false;
                            SDL_FreeSurface(buttons[button]);
                            buttons[button] = TTF_RenderText_Solid(font, btn_labels[button], btn_colors[0]);
                        }
                    }
                break;
                case SDL_MOUSEBUTTONDOWN:
                    x = event.button.x;
                    y = event.button.y;
                    for(int button=0;button<btn_count;button++) {

                        //If mouse clicked over label
                        if( x > btn_pos[button].x && x <= btn_pos[button].x+btn_pos[button].w && y >= btn_pos[button].y && y <= btn_pos[button].y+btn_pos[button].h ) {
                            for(int clicked_button=0;clicked_button<btn_count;clicked_button++)
                                SDL_FreeSurface(buttons[clicked_button]);
                            return button;
                        }
                    }
                break;
            }
        }

        SDL_BlitSurface(header, NULL, game_obj->screen, &header_pos);

        for(int button=0;button<btn_count;button++) {
            SDL_BlitSurface(buttons[button], NULL, game_obj->screen, &btn_pos[button]);
        }
        SDL_Flip(game_obj->screen);
        //if( (Uint32)(1000/game_obj->FPS) > (SDL_GetTicks()-time) )
          //  SDL_Delay(1000/game_obj->FPS-(SDL_GetTicks()-time));
if( (Uint32)(1000/30) > (SDL_GetTicks()-time) )
  SDL_Delay(1000/30-(SDL_GetTicks()-time));

    }
    return NO_ERROR;
}
