#include <stdio.h>
#include "render.h"

void render(const Game *g){
    //2D buffer on the stack sized to the grid
    char buf[g->height][g->width];
    int x,y;
    for(y = 0; y<g->height; ++y){
        for(x = 0;x<g->width; ++x){
            buf[y][x] = ' ';
        }
    }
    
int i,j
// top and bottom borders as '#'
for (int i = 0; i < g->width; ++i) {
    buf[0][i] = '#';
     buf[g->height - 1][i] = '#';
}

// left and right borders as '#'
for (int j = 0; j < g->height; ++j) {
    buf[j][0] = '#';
     buf[j][g->width - 1] = '#';
  }

  //if snake inside the grid place it 0
  if(g->head.x >= 0 && g->head.x <g->width &&
     g->head.y >= 0 && g->head.y < g->height){
     buf[g->head.y][g->head.x] = '0';
  }

  


}