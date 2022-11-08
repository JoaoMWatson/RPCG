#ifndef NPC
#define NPC

typedef struct NPC
{
    int position_x;
    int position_y;
    int width;
    int height;
}npc;

const int common_size = 28;

npc bishop = {17, 6, common_size, common_size};
npc king = {38, 6, common_size, common_size};
npc pawn = {5, 5, common_size, common_size};
npc tower = {27, 5, common_size, common_size};


void bishop_draw(int x, int y, int position_x, int position_y, int size, int width, int height) {
    al_draw_filled_rectangle(x + position_x * size, y + position_y * size, x + position_x * size + width, y + position_y * size + height, al_map_rgb(200, 0, 200));
    
    return;
}


void king_draw(int x, int y, int position_x, int position_y, int size, int width, int height) {
    al_draw_filled_rectangle(x + position_x * size, y + position_y * size, x + position_x * size + width, y + position_y * size + height, al_map_rgb(0, 200, 200));
    
    return;
}


void pawn_draw(int x, int y, int position_x, int position_y, int size, int width, int height) {
    al_draw_filled_rectangle(x + position_x * size, y + position_y * size, x + position_x * size + width, y + position_y * size + height, al_map_rgb(30, 30, 200));
    
    return;
}


void tower_draw(int x, int y, int position_x, int position_y, int size, int width, int height) {
    al_draw_filled_rectangle(x + position_x * size, y + position_y * size, x + position_x * size + width, y + position_y * size + height, al_map_rgb(20, 100, 20));
    
    return;
}


void npc_draw(int x, int y, int size) {
    bishop_draw(x, y, bishop.position_x, bishop.position_y, size, bishop.width, bishop.height);
    king_draw(x, y, king.position_x, king.position_y, size, king.width, king.height);
    pawn_draw(x, y, pawn.position_x, pawn.position_y, size, pawn.width, pawn.height);
    tower_draw(x, y, tower.position_x, tower.position_y, size, tower.width, tower.height);

    return;
} 

#endif