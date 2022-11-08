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
}npc;

const int common_size = 28;
npc bishop = {17, 6, common_size, common_size};
npc king = {38, 6, common_size, common_size};
npc pawn = {5, 5, common_size, common_size};
npc tower = {27, 5, common_size, common_size};

void init_npc(int size) {
    bishop.position_map_x = bishop.position_x * size;
    bishop.position_map_y = bishop.position_y * size;

    king.position_map_x = king.position_x * size;
    king.position_map_y = king.position_y * size;

    pawn.position_map_x = pawn.position_x * size;
    pawn.position_map_y = pawn.position_y * size;

    tower.position_map_x = tower.position_x * size;
    tower.position_map_y = tower.position_y * size;

    return;
}


void each_npc_draw(int x, int y, int position_x, int position_y, int width, int height, int r, int g, int b) {  
    al_draw_filled_rectangle(x + position_x , y + position_y, x + position_x + width, y + position_y + height, al_map_rgb(r, g, b));
    
    return;
}


void npc_draw(int x, int y) {
    each_npc_draw(x, y, bishop.position_map_x, bishop.position_map_y, bishop.width, bishop.height, 0, 100, 200);
    each_npc_draw(x, y, king.position_map_x, king.position_map_y, king.width, king.height, 200, 0, 100);
    each_npc_draw(x, y, pawn.position_map_x, pawn.position_map_y, pawn.width, pawn.height, 100, 200, 100);
    each_npc_draw(x, y, tower.position_map_x, tower.position_map_y, tower.width, tower.height, 100, 20, 100);
    
    return;
} 

#endif