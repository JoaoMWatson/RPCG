#ifndef SCREENPLAY
#define SCREENPLAY

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

void init_each_script_file(FILE *s_file, SCRIPT_FILE *each, int count_lines, char path[]);

void init_script_file(void);

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

void init_bool_script(void);

void script_background(int a);

void next(int *which);

void knight_script(bool *done, int *which, int *play);

void bishop_script(int *which, int *play);

void tower_script(int *which, int *play);

void king_script(int *which, int *play);

void pawn_script(int *which);

void map_script(int *which);

void script_draw(SCRIPT sc);

#endif