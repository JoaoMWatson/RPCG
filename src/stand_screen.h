#ifndef STAND_SCREEN
#define STAND_SCREEN
#include "parallel_game.h"

void cool_draw_text(char m[], int height) {
    time_count();

    if(count_timer > 30) {
        al_draw_text(font, al_map_rgb(185, 185, 185), BUFFER_W/2, height, ALLEGRO_ALIGN_CENTRE, m);
        if(count_timer > 60)
            restart_time();
            al_play_sample_instance(menu_audio_instance);
            al_stop_sample_instance(final_boss_game_audio_instance);
    }

    return;
}

void menu_draw(void) {
    al_draw_text(font_title, al_map_rgb(215, 215, 215), BUFFER_W/2, 10, ALLEGRO_ALIGN_CENTRE, "RPCG");
    al_draw_text(font, al_map_rgb(215, 215, 215), BUFFER_W/2, 50, ALLEGRO_ALIGN_CENTRE, "Role Playing Chess Game");
    cool_draw_text("pressione ENTER para começar", 160);

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


void info_return(void) {
    cool_draw_text("pressione L para recomeçar", BUFFER_H/2 - 30);

    return;
}

#endif