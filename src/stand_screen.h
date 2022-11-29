#ifndef STAND_SCREEN
#define STAND_SCREEN
#include "parallel_game.h"

void menu_draw(void) {
    time_count();

    al_draw_text(font_title, al_map_rgb(215, 215, 215), BUFFER_W/2, 10, ALLEGRO_ALIGN_CENTRE, "RPCG");
    al_draw_text(font, al_map_rgb(215, 215, 215), BUFFER_W/2, 50, ALLEGRO_ALIGN_CENTRE, "Role Playing Chess Game");
    
    if(count_timer > 30) {
        al_draw_text(font, al_map_rgb(185, 185, 185), BUFFER_W/2, 160, ALLEGRO_ALIGN_CENTRE, "pressione ENTER para começar");
        if(count_timer > 60)
            restart_time();
    }

    return;
}


void good_ending(void) {
    al_draw_text(font, al_map_rgb(215, 215, 215), BUFFER_W/2, 5, ALLEGRO_ALIGN_CENTRE, "GOOD ENDING");
    al_draw_text(font_title, al_map_rgb(222, 193, 245), BUFFER_W/2, 20, ALLEGRO_ALIGN_CENTRE, "RAINHA");

    return;
}


void bad_ending(void) {
    al_draw_text(font, al_map_rgb(215, 215, 215), BUFFER_W/2, 5, ALLEGRO_ALIGN_CENTRE, "BAD ENDING");
    al_draw_text(font_title, al_map_rgb(222, 193, 245), BUFFER_W/2, 20, ALLEGRO_ALIGN_CENTRE, "mero PEÃO");

    return;
}

#endif