#ifndef SCREENPLAY
#define SCREENPLAY

typedef struct SCRIPT {
    int x, y;
} SCRIPT;

char me[24];
void knight_script(bool *done, int *which, int *play) {
    switch(*which) {
        case 0:
            strcpy(me, "12345678901234567890123");
            break;

        case 1:
            printf("tudo bem?\n");
            *done = true;
            *play = 2;
            break;
    }

    if(key[ALLEGRO_KEY_E]) {
        *which = *which + 1;
    }
    
    return;
}


void knight_script_draw(void) {
    al_draw_text(font, al_map_rgb(125, 125, 125), 9, BUFFER_H - 30, 0, me);
    al_draw_text(font, al_map_rgb(125, 125, 125), 9, BUFFER_H - 20, 0, me);
    al_draw_text(font, al_map_rgb(125, 125, 125), 9, BUFFER_H - 10, 0, me);
}

#endif