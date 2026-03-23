#ifndef LOGIC_H
#define LOGIC_H
#include "common.h"

typedef struct {
    Vec2 body[MAX_SNAKE_LEN]; 
    int  length;              
    Vec2 dir;                 
    Vec2 next_dir;            
    Vec2 fruit;               
    int  score;
    int  width, height;       
} Game;

void init_game   (Game *g, int w, int h);
void update_game (Game *g, bool *running);
void spawn_fruit (Game *g);
bool is_on_snake (const Game *g, Vec2 pos);

#endif
