#ifndef NPC
#define NPC

typedef struct NPC
{
    int position_x;
    int position_y;
    int width;
    int height;
    int position_map_x;
    int position_map_y;

    ALLEGRO_BITMAP* sprite;
}npc;

const int common_size = 28;
npc bishop = {17, 4, 26, 47};
npc king = {41, 4, 24, 32};
npc knight = {7, 4, 26, 37};
npc tower = {27, 3, 52, 72};

void init_npc(int size);

void each_npc_draw(int x, int y, int position_x, int position_y, int width, int height, int r, int g, int b);

void npc_draw(int x, int y);

void bishop_iteration(int *play);

void king_iteration(int *play);

void knight_iteration(int *play);

void tower_iteration(int *play);

int distance = 5;
bool detect_iteration(int player_x, int player_y, int position_x, int position_y, int width, int height);

bool it_bis;
bool it_kin;
bool it_kni;
bool it_tow;
void npc_update(int player_x, int player_y, int *play);

void destroy_npc(void);

#endif