#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include "common.h"
#include "logic.h"
#include "render.h"
#include "input.h"

int main(void) {
    Game g;
    bool running = true;

    render_init();              /* hide cursor, grab console handle   */
    input_init();
    init_game(&g, 40, 22);     /* 40 wide x 22 tall (incl. borders)  */

    
    render(&g);

    while (running) {
      
        poll_input(&g.dir, &g.next_dir, &running);
        update_game(&g, &running);
        render(&g);
        Sleep(200);           
    }

    render_shutdown();          
    input_shutdown();

    printf("\n\n  *** GAME OVER ***   Final Score: %d\n\n", g.score);
    return 0;
}
