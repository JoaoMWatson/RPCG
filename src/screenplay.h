#ifndef SCREENPLAY
#define SCREENPLAY
#include "parallel_game.h"


typedef struct SCRIPT_FILE {
    int line;
    char speech[50];
} SCRIPT_FILE;

SCRIPT_FILE script_file_knight[60];
const int count_lines_knight = 60;

SCRIPT_FILE script_file_bishop[36];
const int count_lines_bishop = 36;

SCRIPT_FILE script_file_tower[44];
const int count_lines_tower = 44;

SCRIPT_FILE script_file_king[32];
const int count_lines_king = 32;

SCRIPT_FILE script_file_pawn[8];
const int count_lines_pawn = 8;

SCRIPT_FILE script_file_map[32];
const int count_lines_map = 32;

FILE* s_file_knight;
FILE* s_file_bishop;
FILE* s_file_tower;
FILE* s_file_king;
FILE* s_file_pawn;
FILE* s_file_map;


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
    init_each_script_file(s_file_map, script_file_map, count_lines_map, "src/script/map_script.txt");
    return;
}


typedef struct SCRIPT {
    char line[4][50];
    bool map_it;
} SCRIPT;

SCRIPT sc_kni;
SCRIPT sc_bis;
SCRIPT sc_tow;
SCRIPT sc_kin;
SCRIPT sc_paw;
SCRIPT sc_map;

int size_line = 12;


void init_bool_script(void) {
    sc_kni.map_it = false;
    sc_bis.map_it = false;
    sc_tow.map_it = false;
    sc_kin.map_it = false;
    sc_paw.map_it = false;
    sc_map.map_it = false;

    return;
}


void script_background(int a) {
    al_draw_filled_rectangle(0, BUFFER_H - size_line * 5 - 10, BUFFER_W, BUFFER_H, al_map_rgba(0, 0, 0, 205));
    al_draw_rectangle(5, BUFFER_H - size_line * 5 - 5, BUFFER_W - 5, BUFFER_H - 5, al_map_rgb(205, 205, 205), 1);

    return;
}


void next(int *which) {
    if(key[ALLEGRO_KEY_E]) {
        *which = *which + 1;
    }
   //printf("next - %d\n", *which);
    return;
}


void knight_script(bool *done, int *which, int *play) {
    switch(*which) 
    {
        case 0:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 2:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);        
            break;

        case 3:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 4:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 5:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 6:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 7:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 8:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 9:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 10:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 11:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * *which + i].speech);
            break;

        case 12:
            *done = true;
            *play = 2;
            break;

        case 13:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * 12 + i].speech);
            break;

        case 14:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * 13 + i].speech);
            break;

        case 15:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kni.line[i], script_file_knight[4 * 14 + i].speech);
            break;
    }
    next(which); 
    
    return;
}


void bishop_script(int *which, int *play) {
    switch(*which)
    {
        case 0:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 2:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 3:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 4:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 5:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 6:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 7:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;

        case 8:
            for(int i = 0; i < 4; i++)
                strcpy(sc_bis.line[i], script_file_bishop[4 * *which + i].speech);
            break;
    }
    next(which);

    return;
}


void tower_script(int *which, int *play) {
    switch (*which)
    {
        case 0:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 2:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 3:
            for(int i = 0; i < 4; i++)
                    strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 4:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 5:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 6:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 7:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 8:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 9:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;

        case 10:
            for(int i = 0; i < 4; i++)
                strcpy(sc_tow.line[i], script_file_tower[4 * *which + i].speech);
            break;
    }
    next(which);

    return;
}


void king_script(int *which, int *play) {
    switch (*which)
    {
        case 0:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 2:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 3:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 4:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 5:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 6:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    
        case 7:
            for(int i = 0; i < 4; i++)
                strcpy(sc_kin.line[i], script_file_king[4 * *which + i].speech);
            break;
    }
    next(which);


    return;
}


void pawn_script(int *which) {
    switch(*which)
    {
        case 0:
            for(int i = 0; i < 4; i++)
                strcpy(sc_paw.line[i], script_file_pawn[4 * *which + i].speech);
            break;

        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_paw.line[i], script_file_pawn[4 * *which + i].speech);
            break;
    }

    return;
}


void map_script(int *which) {
    switch(*which)
    {
        case 0:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 1:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 2:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 3:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 4:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 5:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 6:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;

        case 7:
            for(int i = 0; i < 4; i++)
                strcpy(sc_map.line[i], script_file_map[4 * *which + i].speech);
            break;
    }
    next(which);

    return;
}


void script_draw(SCRIPT sc) {
    script_background(205);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 5 - 2, 0, sc.line[0]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 4 - 2, 0, sc.line[1]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 3 - 2, 0, sc.line[2]);
    al_draw_text(font, al_map_rgb(255, 255, 255), 9, BUFFER_H - size_line * 2 - 2, 0, sc.line[3]);

}

#endif