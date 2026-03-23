#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "input.h"


void input_init(void) {
    /* Nothing to set up for basic WASD/Q */
}

void input_shutdown(void) {
    /* Nothing to restore */
}

void poll_input(Vec2 *dir,bool *running){
    if(!_kbhit()){
        return; //when no key id pressed
    }
    int c = _getch(); // read key without waiting for user hit enter
    switch(c){
        case 'w' : case 'W' : dir->x = 0; dir->y = -1; break;
        case 's' : case 'S' : dir->x = 0; dir->y = 1; break;
        case 'a' : case 'A' : dir->x = -1; dir->y = 0; break;
        case 'd' : case 'D' : dir->x = 1; dir->y = 0; break;
        case 'q' : case 'Q' : *running = false; //quit
        default : break;

    }
}