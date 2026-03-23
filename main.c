#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "common.h"
#include "logic.h"
#include "render.h"
#include "input.h"

int main(){
    Game g;
    bool running = true;

    init_game(&g,30,20); //grid width,height
    input_init();

    while(running){
        render(&g);// draw the current game grid to the console
        poll_input(&g.dir, &running); // read any pending keypress; update direction or set running=false
        update_game(&g, &running); // advance game state (move snake, detect collisions, etc.)
        Sleep(80);// pause ~80 ms to cap the frame rate
    }

    input_shutdown();
    printf("\n!Game Over!\n");
    return 0;

}