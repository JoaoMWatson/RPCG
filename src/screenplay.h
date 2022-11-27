#ifndef SCREENPLAY
#define SCREENPLAY
#include "parallel_game.h"


typedef struct SCRIPT_FILE {
    int line;
    char speech[44];
} SCRIPT_FILE;
SCRIPT_FILE script_file_knight[4];
const int count_lines_knight = 4;


FILE* s_file_knight;


void init_each_script_file(FILE *s_file, SCRIPT_FILE *each, int count_lines, char path[]) {
    s_file = fopen(path, "r");

    if(s_file == NULL) {
        fprintf(stderr, "Arquivo de script não foi aberto\n");
        exit(1);
    }

    for(int i = 0; i < count_lines; i++) {
        fscanf(s_file, "%d", &each[i].line);
        fscanf(s_file, "%[^\n]s", each[i].speech);
    }

    fclose(s_file);
    
    return;
}

void init_script_file(void) {
    init_each_script_file(s_file_knight, script_file_knight, count_lines_knight, "src/script/knight_script.txt");
    //printf("%d - %s\n", script_file_knight[1].line, script_file_knight[1].speech);
    return;
}


typedef struct SCRIPT {
    char line[4][44];;
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
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[i].speech);
            break;

        case 1:
            strcpy(sc_kni.line[0], "Cavaleiro, por favor ");
            strcpy(sc_kni.line[1], "não me mate.");
            strcpy(sc_kni.line[2], "");
            strcpy(sc_kni.line[3], "");
            break;

        case 2:           
            *done = true;
            *play = 2;
            break;

        case 3:
            strcpy(sc_kni.line[0], "Você deveria ir falar com ");
            strcpy(sc_kni.line[1], " o bispo e a torre eles ");
            strcpy(sc_kni.line[2], "estavam muito interessados em ");
            strcpy(sc_kni.line[3], "te conhecer");
            break;

        case 4:
            strcpy(sc_kni.line[0], "Você deveria ir falar com ");
            strcpy(sc_kni.line[1], " a torre ela ");
            strcpy(sc_kni.line[2], "estava muito interessados em ");
            strcpy(sc_kni.line[3], "te conhecer");
            break;

        case 5:
            strcpy(sc_kni.line[0], "Parabens");
            strcpy(sc_kni.line[1], " Eles falaram que você foi bem");
            strcpy(sc_kni.line[2], "se sinta a vontade para ");
            strcpy(sc_kni.line[3], "explorar");
            break;
    }
    next(which); 
    
    return;
}

/*
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
*/

void knight_script_draw(void) {
    script_background(205);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 5 - 2, 0, sc_kni.line[0]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 4 - 2, 0, sc_kni.line[1]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 3 - 2, 0, sc_kni.line[2]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 2 - 2, 0, sc_kni.line[3]);

}

#endif