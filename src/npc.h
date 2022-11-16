#ifndef NPC
#define NPC
#include "parallel_game.h"

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
npc knight = {5, 5, common_size, common_size};
npc tower = {27, 5, common_size, common_size};


void init_npc(int size) {
    bishop.position_map_x = bishop.position_x * size;
    bishop.position_map_y = bishop.position_y * size;

    king.position_map_x = king.position_x * size;
    king.position_map_y = king.position_y * size;

    knight.position_map_x = knight.position_x * size;
    knight.position_map_y = knight.position_y * size;

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
    each_npc_draw(x, y, knight.position_map_x, knight.position_map_y, knight.width, knight.height, 100, 200, 100);
    each_npc_draw(x, y, tower.position_map_x, tower.position_map_y, tower.width, tower.height, 100, 20, 100);
    
    return;
}


void bishop_iteration(int *play) {
    *play = 3;
    printf("bishop\n");
    return;
}


void king_iteration(int *play) {
    *play = 4;
    printf("king\n");
    return;
}


void knight_iteration(int *play) {
    *play = 5;
    printf("knight\n");
    return;
}


void tower_iteration(int *play) {
    *play = 6;
    printf("tower\n");
    return;
}


int distance = 5;
bool detect_iteration(int player_x, int player_y, int position_x, int position_y, int width, int height) {
    if(player_y + PROTAGONIST_H + distance >= position_y 
    && player_y - distance <= position_y + height
    && player_x + PROTAGONIST_W + distance >= position_x
    && player_x - distance <= position_x + width)
        return true;
    
    return false;
}


bool it_bis;
bool it_kin;
bool it_kni;
bool it_tow;
void npc_update(int player_x, int player_y, int *play) {
    if(key[ALLEGRO_KEY_E]) {
        it_bis = detect_iteration(player_x, player_y, bishop.position_map_x, bishop.position_map_y, bishop.width, bishop.height);
        it_kin = detect_iteration(player_x, player_y, king.position_map_x, king.position_map_y, king.width, king.height);
        it_kni = detect_iteration(player_x, player_y, knight.position_map_x, knight.position_map_y, knight.width, knight.height);
        it_tow = detect_iteration(player_x, player_y, tower.position_map_x, tower.position_map_y, tower.width, tower.height);

        if(it_bis) {
            if(!parallel_player.bishop_done) { 
                init_parallel_player();
                init_enemy();
                init_shot();
                bishop_iteration(play);
            }
        } else if(it_kin) {
            if(!parallel_player.king_done) { 
                init_parallel_player();
                init_enemy();
                king_iteration(play);
            }
        } else if(it_kni) {
            if(!parallel_player.knight_done) {
                init_parallel_player();
                init_enemy();
                init_shot();
                knight_iteration(play);
            }
        } else if(it_tow) {
            if(!parallel_player.tower_done) {
                init_parallel_player();
                init_enemy();
                init_shot();
                tower_iteration(play);
            }
        }
    } 

    return;
}

#endif