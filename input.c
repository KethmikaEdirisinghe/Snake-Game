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

void poll_input(const Vec2 *cur, Vec2 *next, bool *running) {
  
    while (_kbhit()) {
        int  c  = _getch();
        Vec2 nd = *next;   /* default: keep whatever was queued before */

        switch (c) {
            case 'w': case 'W': nd = (Vec2){ 0, -1}; break;
            case 's': case 'S': nd = (Vec2){ 0,  1}; break;
            case 'a': case 'A': nd = (Vec2){-1,  0}; break;
            case 'd': case 'D': nd = (Vec2){ 1,  0}; break;
            case 'q': case 'Q': *running = false; return;
            default : continue;   /* ignore unrelated keys */
        }

      
        if (nd.x == -cur->x && nd.y == -cur->y)
            continue;

        *next = nd;
    }
}