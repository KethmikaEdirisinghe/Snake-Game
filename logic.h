#ifndef LOGIC_H
#define LOGIC_H
#include "common.h"

typedef struct {
    Vec2 head;// head of the snake
    Vec2 dir; //current direction
    int width,height; //Grrid size

}Game;

void init_game(Game *g, int w, int h);
void update_game(Game *g, bool *running);

#endif