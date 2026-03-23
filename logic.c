#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <stdbool.h>
#include <time.h>


bool is_on_snake(const Game *g, Vec2 pos) {
    for (int i = 0; i < g->length; i++)
        if (g->body[i].x == pos.x && g->body[i].y == pos.y)
            return true;
    return false;
}


void spawn_fruit(Game *g) {
    Vec2 pos;
    int tries = 0;
    
    do {
        pos.x = 1 + rand() % (g->width  - 2);
        pos.y = 1 + rand() % (g->height - 2);
    } while (is_on_snake(g, pos) && ++tries < 2000);
    g->fruit = pos;
}

void init_game(Game *g, int w, int h) {
    srand((unsigned)time(NULL));
    g->width  = w;
    g->height = h;

   
    g->length   = 3;
    g->body[0]  = (Vec2){ w / 2,     h / 2 };
    g->body[1]  = (Vec2){ w / 2 - 1, h / 2 };
    g->body[2]  = (Vec2){ w / 2 - 2, h / 2 };
    g->dir      = (Vec2){ 1, 0 };   /* start moving right */
    g->next_dir = (Vec2){ 1, 0 };
    g->score    = 0;

    spawn_fruit(g);
}


void update_game(Game *g, bool *running) {
    /* Commit the queued direction (already validated against reversal) */
    g->dir = g->next_dir;

    /* Compute where the head will move */
    Vec2 nh = { g->body[0].x + g->dir.x,
                g->body[0].y + g->dir.y };

    /* ── Wall collision ── */
    if (nh.x <= 0 || nh.x >= g->width  - 1 ||
        nh.y <= 0 || nh.y >= g->height - 1) {
        *running = false;
        return;
    }

    /* ── Self collision  ── */
    for (int i = 0; i < g->length - 1; i++) {
        if (g->body[i].x == nh.x && g->body[i].y == nh.y) {
            *running = false;
            return;
        }
    }

    /* ── Fruit collision ── */
    bool ate = (nh.x == g->fruit.x && nh.y == g->fruit.y);
    if (ate && g->length < MAX_SNAKE_LEN)
        g->length++;   /* grow: one extra segment survives the shift */

    /* ── Shift body (tail drops off unless we grew) ── */
    for (int i = g->length - 1; i > 0; i--)
        g->body[i] = g->body[i - 1];
    g->body[0] = nh;

    if (ate) {
        g->score++;
        spawn_fruit(g);
    }
}
