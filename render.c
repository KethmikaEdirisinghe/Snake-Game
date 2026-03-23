#include <stdio.h>
#include <stdlib.h>
#include "render.h"

void render(const Game *g){
    //2D buffer on the stack sized to the grid
    char buf[g->height][g->width];
    
    for(int y = 0; y<g->height; ++y){
        for(int x = 0;x<g->width; ++x){
            buf[y][x] = ' ';
        }
    }
    
// top and bottom borders as '#'
for ( int x = 0; x < g->width; ++x) {
    buf[0][x] = '#';
     buf[g->height - 1][x] = '#';
}

// left and right borders as '#'
for (int y = 0; y < g->height; ++y) {
    buf[y][0] = '#';
     buf[y][g->width - 1] = '#';
  }

  //if snake inside the grid place it 0
  if(g->head.x >= 0 && g->head.x <g->width &&
     g->head.y >= 0 && g->head.y < g->height){
     buf[g->head.y][g->head.x] = '0';
  }

  //clear the console and move cursor to top-left
  /*
  \x1b is the ESC character (0x1B).
[2J means “clear the entire screen.”
[H means “move the cursor to home” (row 0, col 0).
  */
  //printf("\x1b[2J\x1b[H");
  system("cls");


for(int y=0; y < g->height; ++y){

    for(int x = 0; x < g->width; ++x ){
        putchar(buf[y][x]);
    }
    putchar('\n');
  }

//help
printf("Use WASD to move, Q to quit\n");  

}