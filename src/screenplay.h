#ifndef SCREENPLAY
#define SCREENPLAY
#include "parallel_game.h"

const int count_lines = 2;
typedef struct SCRIPT_FILE {
    int character;
    int line;
    char speech[39];
} SCRIPT_FILE;
SCRIPT_FILE script_file[2];

FILE* s_file;
void init_script_file(void) {
    s_file = fopen("src/script/script.txt", "r");
    if(s_file == NULL) {
        fprintf(stderr, "Arquivo de script não foi aberto\n");
        exit(1);
    }

    for(int i = 0; i < count_lines; i++) {
        fscanf(s_file, "%d", &script_file[i].character);
        fscanf(s_file, "%d", &script_file[i].line);
        fscanf(s_file, "%[^\n]s", script_file[i].speech);
    }

    fclose(s_file);
    printf("%d - ", script_file[0].character);
    printf("%d - ", script_file[0].line);
    printf("%s\n", script_file[0].speech);
    printf("%d - ", script_file[1].character);
    printf("%d - ", script_file[1].line);
    printf("%s\n", script_file[1].speech);
    return;
}


typedef struct SCRIPT {
    char line_one[39];
    char line_two[39];
    char line_three[39];
    char line_four[39];
    bool map_it;
} SCRIPT;

SCRIPT sc_kni;
SCRIPT sc_bis;
SCRIPT sc_tow;
SCRIPT sc_kin;

int size_line = 12;


void script_background(int a) {
    al_draw_filled_rectangle(0, BUFFER_H - size_line * 5 - 10, BUFFER_W, BUFFER_H, al_map_rgba(0, 0, 0, 205));
    al_draw_rectangle(5, BUFFER_H - size_line * 5 - 5, BUFFER_W - 5, BUFFER_H - 5, al_map_rgb(205, 205, 205), 1);

    return;
}


void next(int *which) {
    if(key[ALLEGRO_KEY_E]) {
        *which = *which + 1;
    }
    printf("next - %d\n", *which);
    return;
}


void knight_script(bool *done, int *which, int *play) {
    switch(*which) {
        case 0:
            strcpy(sc_kni.line_one, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_two, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_three, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_four, "01234567890123456789012345678901234567");
            break;

        case 1:
            strcpy(sc_kni.line_one, "Cavaleiro, por favor ");
            strcpy(sc_kni.line_two, "não me mate.");
            strcpy(sc_kni.line_three, "");
            strcpy(sc_kni.line_four, "");
            break;

        case 2:           
            *done = true;
            *play = 2;
            break;

        case 3:
            strcpy(sc_kni.line_one, "Você deveria ir falar com ");
            strcpy(sc_kni.line_two, " o bispo e a torre eles ");
            strcpy(sc_kni.line_three, "estavam muito interessados em ");
            strcpy(sc_kni.line_four, "te conhecer");
            break;

        case 4:
            strcpy(sc_kni.line_one, "Você deveria ir falar com ");
            strcpy(sc_kni.line_two, " a torre ela ");
            strcpy(sc_kni.line_three, "estava muito interessados em ");
            strcpy(sc_kni.line_four, "te conhecer");
            break;

        case 5:
            strcpy(sc_kni.line_one, "Parabens");
            strcpy(sc_kni.line_two, " Eles falaram que você foi bem");
            strcpy(sc_kni.line_three, "se sinta a vontade para ");
            strcpy(sc_kni.line_four, "explorar");
            break;
    }
    next(which); 
    
    return;
}


void bishop_script(bool *done, int *which, int *play) {
    switch(*which) {
        case 0:
            strcpy(sc_kni.line_one, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_two, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_three, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_four, "01234567890123456789012345678901234567");
            break;

        case 1:
            strcpy(sc_kni.line_one, "Cavaleiro, por favor ");
            strcpy(sc_kni.line_two, "não me mate.");
            strcpy(sc_kni.line_three, "");
            strcpy(sc_kni.line_four, "");
            break;
    }
    
    return;
}


void tower_script(bool *done, int *which, int *play) {
    switch(*which) {
        case 0:
            strcpy(sc_kni.line_one, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_two, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_three, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_four, "01234567890123456789012345678901234567");
            break;

        case 1:
            strcpy(sc_kni.line_one, "Cavaleiro, por favor ");
            strcpy(sc_kni.line_two, "não me mate.");
            strcpy(sc_kni.line_three, "");
            strcpy(sc_kni.line_four, "");
            break;
    }
    
    return;
}


void king_script(bool *done, int *which, int *play) {
    switch(*which) {
        case 0:
            strcpy(sc_kni.line_one, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_two, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_three, "01234567890123456789012345678901234567");
            strcpy(sc_kni.line_four, "01234567890123456789012345678901234567");
            break;

        case 1:
            strcpy(sc_kni.line_one, "Cavaleiro, por favor ");
            strcpy(sc_kni.line_two, "não me mate.");
            strcpy(sc_kni.line_three, "");
            strcpy(sc_kni.line_four, "");
            break;
    }
    
    return;
}


void knight_script_draw(void) {
    script_background(205);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 4 - 2, 0, sc_kni.line_two);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 5 - 2, 0, sc_kni.line_one);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 3 - 2, 0, sc_kni.line_three);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 2 - 2, 0, sc_kni.line_four);

}

#endif