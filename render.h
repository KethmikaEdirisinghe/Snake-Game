#ifndef RENDER_H
#define RENDER_H
#include "logic.h"

void render_init    (void);   /* hide cursor, grab console handle */
void render_shutdown(void);   /* restore cursor                   */
void render         (const Game *g);

#endif
