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


void pawn_iteration(int *play) {
    *play = 5;
    printf("pawn\n");
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
bool it_paw;
bool it_tow;
void npc_update(int player_x, int player_y, int *play) {
    if(key[ALLEGRO_KEY_E]) {
        it_bis = detect_iteration(player_x, player_y, bishop.position_map_x, bishop.position_map_y, bishop.width, bishop.height);
        it_kin = detect_iteration(player_x, player_y, king.position_map_x, king.position_map_y, king.width, king.height);
        it_paw = detect_iteration(player_x, player_y, pawn.position_map_x, pawn.position_map_y, pawn.width, pawn.height);
        it_tow = detect_iteration(player_x, player_y, tower.position_map_x, tower.position_map_y, tower.width, tower.height);

        if(it_bis) {
            bishop_iteration(play);
        } else if(it_kin) {
            king_iteration(play);
        } else if(it_paw) {
            pawn_iteration(play);
        } else if(it_tow) {
            tower_iteration(play);
        }
    } 

    return;
}


#define PARALLEL_PROTAGONIST_W 10
#define PARALLEL_PROTAGONIST_H 10
#define PARALLEL_PROTAGONIST_SPEED 2
#define PARALLEL_PROTAGONIST_MAX_X (BUFFER_W - PARALLEL_PROTAGONIST_W)
#define PARALLEL_PROTAGONIST_MAX_Y (BUFFER_H - PARALLEL_PROTAGONIST_H)

typedef struct PARALLEL_PLAYER {
    int x, y;
} PARALLEL_PLAYER;
PARALLEL_PLAYER parallel_player;


void init_parallel_player(void) {
    parallel_player.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    parallel_player.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);

    return;
}


void parallel_player_update(void) {
    if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A])
        parallel_player.x -= PARALLEL_PROTAGONIST_SPEED;
    else if(key[ALLEGRO_KEY_RIGHT] || key[ALLEGRO_KEY_D])
        parallel_player.x += PARALLEL_PROTAGONIST_SPEED;
    else if(key[ALLEGRO_KEY_UP] || key[ALLEGRO_KEY_W])
        parallel_player.y -= PARALLEL_PROTAGONIST_SPEED;
    else if(key[ALLEGRO_KEY_DOWN] || key[ALLEGRO_KEY_S])
        parallel_player.y += PARALLEL_PROTAGONIST_SPEED;

    if(parallel_player.x < 0)
        parallel_player.x = 0;
    if(parallel_player.y < 0)
        parallel_player.y = 0;
   
    if(parallel_player.x > PARALLEL_PROTAGONIST_MAX_X)
        parallel_player.x = PARALLEL_PROTAGONIST_MAX_X;
    if(parallel_player.y > PARALLEL_PROTAGONIST_MAX_Y)
        parallel_player.y = PARALLEL_PROTAGONIST_MAX_Y;

    // printf("\n%d, %d", parallel_player.x, parallel_player.y);
    
    return;
}


void parallel_player_draw(void) {
    al_draw_filled_rectangle(parallel_player.x, parallel_player.y, parallel_player.x + PARALLEL_PROTAGONIST_W, parallel_player.y + PARALLEL_PROTAGONIST_H, al_map_rgb(255, 255, 255));

    return;
}

#endif