#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "render.h"

/*  Win32 console helpers  */

static HANDLE hOut;

void render_init(void) {
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

   
    CONSOLE_CURSOR_INFO ci = {1, FALSE};
    SetConsoleCursorInfo(hOut, &ci);
}

void render_shutdown(void) {
    /* Restore visible cursor when the game exits */
    CONSOLE_CURSOR_INFO ci = {1, TRUE};
    SetConsoleCursorInfo(hOut, &ci);
}

static void cursor_home(void) {
    COORD c = {0, 0};
    SetConsoleCursorPosition(hOut, c);
}

/*  Main render function  */

void render(const Game *g) {

    /*  1. Build character grid  */
    char grid[MAX_GRID_H][MAX_GRID_W];
    memset(grid, ' ', sizeof(grid));

    /* Borders */
    for (int x = 0; x < g->width;  x++) {
        grid[0][x]            = '#';
        grid[g->height-1][x]  = '#';
    }
    for (int y = 0; y < g->height; y++) {
        grid[y][0]           = '#';
        grid[y][g->width-1]  = '#';
    }

    /* Fruit — shown as '$' */
    if (g->fruit.x > 0 && g->fruit.x < g->width  - 1 &&
        g->fruit.y > 0 && g->fruit.y < g->height - 1)
        grid[g->fruit.y][g->fruit.x] = '$';

    /* Snake — tail to head so the head character wins on overlap
       '@' = head,  'o' = body segment                               */
    for (int i = g->length - 1; i >= 0; i--) {
        Vec2 p = g->body[i];
        if (p.x >= 0 && p.x < g->width &&
            p.y >= 0 && p.y < g->height)
            grid[p.y][p.x] = (i == 0) ? '@' : 'o';
    }

  
    char out[MAX_GRID_H * (MAX_GRID_W + 2) + 512];
    int  n = 0;

    for (int y = 0; y < g->height; y++) {
        for (int x = 0; x < g->width; x++)
            out[n++] = grid[y][x];
        out[n++] = '\n';
    }

    /* Status bar — trailing spaces overwrite any stale characters    */
    n += sprintf(out + n,
        "+-----------------------------------------+\n"
        "| Score: %-4d  Length: %-4d               |\n"
        "| Head : (%2d, %2d)  Dir: [%+d, %+d]         |\n"
        "| WASD = move     Q = quit                |\n"
        "+-----------------------------------------+\n",
        g->score, g->length,
        g->body[0].x, g->body[0].y,
        g->dir.x, g->dir.y);

    /*  3. Reposition cursor and blast the buffer out */
    cursor_home();
    fwrite(out, 1, n, stdout);
    fflush(stdout);
}
