#ifndef INPUT_H
#define INPUT_H
#include "common.h"
#include <stdbool.h>


void input_init(void);
void input_shutdown(void);
void poll_input(Vec2 *dir, bool *running);

#endif
