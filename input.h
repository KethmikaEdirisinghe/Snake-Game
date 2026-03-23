#ifndef INPUT_H
#define INPUT_H
#include "common.h"
#include <stdbool.h>

void input_init(void);
void input_shutdown(void);

void poll_input(const Vec2 *current_dir, Vec2 *next_dir, bool *running);

#endif
