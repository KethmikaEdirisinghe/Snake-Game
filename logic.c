#include <stdio.h>
#include "logic.h"
#include <stdbool.h>

void init_game(Game *g, int w, int h){
    g->width = w;
    g->height = h;
    g->head =(Vec2){w/2, h/2}; // start from middle
    g->dir = (Vec2){1, 0};  // by default righ side drieection start
    
}

void update_game(Game *g, bool *running){
    //advance head by current direction

    g->head.x+= g->dir.x;
    g->head.y+= g->dir.y;

    //wall collision ends the game
    if(g->head.x<0 || g->head.x >= g->width ||
       g->head.y<0 || g->head.y >= g->height){
       *running = false;
    }
}