#ifndef SCREENPLAY
#define SCREENPLAY
#include "parallel_game.h"


typedef struct SCRIPT_FILE {
    int line;
    char speech[44];
} SCRIPT_FILE;

SCRIPT_FILE script_file_knight[16];
const int count_lines_knight = 16;

SCRIPT_FILE script_file_bishop[16];
const int count_lines_bishop = 16;

SCRIPT_FILE script_file_tower[16];
const int count_lines_tower = 16;

SCRIPT_FILE script_file_king[16];
const int count_lines_king = 16;

SCRIPT_FILE script_file_pawn[16];
const int count_lines_pawn = 16;


FILE* s_file_knight;
FILE* s_file_bishop;
FILE* s_file_tower;
FILE* s_file_king;
FILE* s_file_pawn;


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
    init_each_script_file(s_file_bishop, script_file_bishop, count_lines_bishop, "src/script/bishop_script.txt");
    init_each_script_file(s_file_tower, script_file_tower, count_lines_tower, "src/script/tower_script.txt");
    init_each_script_file(s_file_king, script_file_king, count_lines_king, "src/script/king_script.txt");
    init_each_script_file(s_file_pawn, script_file_pawn, count_lines_pawn, "src/script/pawn_script.txt");
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
SCRIPT sc_paw;

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
                strcpy(sc_kni.line[i], script_file_knight[4 * 0 + i].speech);
            break;

        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * 1 + i].speech);
            break;

        case 2:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * 2 + i].speech);        
            break;

        case 3:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * 3 + i].speech);
            break;

        case 4:
            *done = true;
            *play = 2;
            break;
    }
    next(which); 
    
    return;
}

/*
void bishop_script(int *which, int *play) {
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

void script_draw(SCRIPT sc) {
    script_background(205);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 5 - 2, 0, sc.line[0]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 4 - 2, 0, sc.line[1]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 3 - 2, 0, sc.line[2]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 2 - 2, 0, sc.line[3]);

}

#endif