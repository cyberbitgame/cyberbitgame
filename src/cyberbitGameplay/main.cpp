#include <iostream>
#include "gameplay.h"

int main(int argc,
		 char* argv[])
{
    if(DEV) {
        //Allow console output
        freopen( "CON", "wt", stdout );
    }

	//Initialize player, enemy and game
	GamePlay CyberBitGame;
	return EXIT_SUCCESS;

}
