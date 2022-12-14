#include "npc.h"
#include "../parallel_game/parallel_game.h"
#include "../screenplay/screenplay.h"


void init_npc(int size) {
    bishop.position_map_x = bishop.position_x * size;
    bishop.position_map_y = bishop.position_y * size;
    bishop.sprite = al_load_bitmap("src/images/bishop.png");
    must_init(true, bishop.sprite, "bishop sprite");

    king.position_map_x = king.position_x * size;
    king.position_map_y = king.position_y * size;
    king.sprite = al_load_bitmap("src/images/king.png");
    must_init(true, king.sprite, "king sprite");

    knight.position_map_x = knight.position_x * size;
    knight.position_map_y = knight.position_y * size;
    knight.sprite = al_load_bitmap("src/images/horse.png");
    must_init(true, knight.sprite, "knight sprite");

    tower.position_map_x = tower.position_x * size;
    tower.position_map_y = tower.position_y * size;
    tower.sprite = al_load_bitmap("src/images/tower.png");
    must_init(true, tower.sprite, "tower sprite");

    return;
}


void each_npc_draw(int x, int y, int position_x, int position_y, int width, int height, int r, int g, int b) {  
    al_draw_filled_rectangle(x + position_x , y + position_y, x + position_x + width, y + position_y + height, al_map_rgb(r, g, b));
    
    return;
}


void npc_draw(int x, int y) {
    //each_npc_draw(x, y, bishop.position_map_x, bishop.position_map_y, bishop.width, bishop.height, 0, 100, 200);
    //each_npc_draw(x, y, king.position_map_x, king.position_map_y, king.width, king.height, 200, 0, 100);
    //each_npc_draw(x, y, knight.position_map_x, knight.position_map_y, knight.width, knight.height, 100, 200, 100);
    //each_npc_draw(x, y, tower.position_map_x, tower.position_map_y, tower.width, tower.height, 100, 20, 100);
    al_draw_bitmap(knight.sprite, x + knight.position_map_x - 9, y + knight.position_map_y - 2, 0);
    al_draw_bitmap(king.sprite, x + king.position_map_x, y + king.position_map_y, 0);
    al_draw_bitmap(bishop.sprite, x + bishop.position_map_x, y + bishop.position_map_y, 0);
    al_draw_bitmap(tower.sprite, x + tower.position_map_x - 8, y + tower.position_map_y, 0);
    
    return;
}


void bishop_iteration(int *play) {
    *play = BISHOP_GAME;
    printf("bishop\n");
    return;
}


void king_iteration(int *play) {
    *play = KING_GAME;
    printf("king\n");
    return;
}


void knight_iteration(int *play) {
    *play = KNIGHT_GAME;
    printf("knight\n");
    return;
}


void tower_iteration(int *play) {
    *play = TOWER_GAME;
    printf("tower\n");
    return;
}


bool detect_iteration(int player_x, int player_y, int position_x, int position_y, int width, int height) {
    if(player_y + PROTAGONIST_H + distance >= position_y 
    && player_y - distance <= position_y + height
    && player_x + PROTAGONIST_W + distance >= position_x
    && player_x - distance <= position_x + width)
        return true;
    
    return false;
}


void npc_update(int player_x, int player_y, int *play) {
    tic_tac = time_count();
    it_bis = detect_iteration(player_x, player_y, bishop.position_map_x, bishop.position_map_y, bishop.width, bishop.height);
    it_kin = detect_iteration(player_x, player_y, king.position_map_x, king.position_map_y, king.width, king.height);
    it_kni = detect_iteration(player_x, player_y, knight.position_map_x, knight.position_map_y, knight.width, knight.height);
    it_tow = detect_iteration(player_x, player_y, tower.position_map_x, tower.position_map_y, tower.width, tower.height);

    if(key[ALLEGRO_KEY_E] && count_timer > 2) {
        /*
        printf("kni - %s, bis - %s, tow - %s, kin - %s\n",
                parallel_player.knight_done? "true" : "false", 
                parallel_player.bishop_done? "true" : "false",
                parallel_player.tower_done? "true" : "false",
                parallel_player.king_done? "true" : "false");
        */

        if(it_bis) {
            if(!parallel_player.bishop_done && !parallel_player.knight_done) {
                sc_bis.map_it = !sc_bis.map_it;
                player.bishop = 0;
                bishop_script(&player.bishop, play);
            } 
            else if(!parallel_player.bishop_done && parallel_player.knight_done) { 
                if(player.bishop < 7) {
                    if(player.bishop == 0)
                        player.bishop = 1;
                    sc_bis.map_it = true;
                    bishop_script(&player.bishop, play);
                } else {
                    sc_bis.map_it = false;
                    init_parallel_player();
                    init_enemy_game();
                    init_shot();
                    bishop_iteration(play);
                }
            } 
            else if(parallel_player.bishop_done && !parallel_player.tower_done) {
                sc_bis.map_it = !sc_bis.map_it;
                player.bishop = 7;
                bishop_script(&player.bishop, play);
            } 
            else if(parallel_player.bishop_done && parallel_player.tower_done) {
                sc_bis.map_it = !sc_bis.map_it;
                player.bishop = 8;
                bishop_script(&player.bishop, play);
            }
        } 
        else if(it_kin) {
            if(!parallel_player.king_done && !parallel_player.knight_done) {
                sc_kin.map_it = !sc_kin.map_it;
                player.king = 0;
                king_script(&player.king, play);
            }
            else if(!parallel_player.king_done && (!parallel_player.bishop_done || !parallel_player.tower_done)) {
                sc_kin.map_it = !sc_kin.map_it;
                player.king = 1;
                king_script(&player.king, play);
            }
            else if(!parallel_player.king_done && parallel_player.tower_done) { 
                if(player.king < 8) {
                    if(player.king < 2)
                        player.king = 2;
                    sc_kin.map_it = true;
                    king_script(&player.king, play);
                } else {
                    sc_kin.map_it = false;
                    init_parallel_player();
                    init_enemy_game();
                    init_shot();
                    init_shot_player();
                    king_iteration(play);
                }
            }
        } 
        else if(it_kni) {
            if(!parallel_player.knight_done) {
                init_enemy_game();
                knight_iteration(play);
            } 
            else if(!parallel_player.tower_done && !parallel_player.bishop_done){
                sc_kni.map_it = !sc_kni.map_it;
                player.knight = 13;
                knight_script(&parallel_player.knight_done, &player.knight, play);
            } 
            else if(!parallel_player.tower_done) {
                sc_kni.map_it = !sc_kni.map_it;
                player.knight = 14;
                knight_script(&parallel_player.knight_done, &player.knight, play);
            } 
            else if(!parallel_player.king_done) {
                sc_kni.map_it = !sc_kni.map_it;
                player.knight = 15;
                knight_script(&parallel_player.knight_done, &player.knight, play);
            }
        } 
        else if(it_tow) {
            if(!parallel_player.tower_done && !parallel_player.knight_done) {
                sc_tow.map_it = !sc_tow.map_it;
                player.tower = 0;
                tower_script(&player.tower, play);
            }
            else if(!parallel_player.tower_done && !parallel_player.bishop_done) {
                sc_tow.map_it = !sc_tow.map_it;
                player.tower = 1;
                tower_script(&player.tower, play);
            }
            else if(!parallel_player.tower_done && parallel_player.bishop_done) {
                if(player.tower < 10) {
                    if(player.tower < 2)
                        player.tower = 2;
                    sc_tow.map_it = true;
                    tower_script(&player.tower, play);
                } else {
                    sc_tow.map_it = false;
                    init_parallel_player();
                    init_enemy_game();
                    init_shot();
                    tower_iteration(play);
                }
            }
            else if(parallel_player.tower_done) {
                sc_tow.map_it = !sc_tow.map_it;
                player.tower = 10;
                tower_script(&player.tower, play);
            }
        }
        restart_time();
    } 

    return;
}


void destroy_npc(void) {
    al_destroy_bitmap(knight.sprite);
    
    return;
}