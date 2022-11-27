#ifndef PARALLEL_GAME
#define PARALLEL_GAME
#include "map.h"
#include "screenplay.h"

int count_timer = 0;
int tic_tac;

void restart_time(void) {
    count_timer = 0;
    
    return;
}

int time_count(void) {
    int timer_counted;

    al_set_timer_count(timer, count_timer++);
    timer_counted = (int) count_timer/30;

    return timer_counted;
}

void game_over(bool *lost, int *play) {
    tic_tac = time_count();

    if(tic_tac < 2) {
    al_draw_filled_rectangle(0, BUFFER_H/4, BUFFER_W, BUFFER_H - BUFFER_H/4, al_map_rgba(35, 35, 35, 205));

    al_draw_rectangle(0 + 6, BUFFER_H/4 + 6, BUFFER_W - 6, BUFFER_H - BUFFER_H/4 - 6, al_map_rgba(205, 205, 205, 205), 0);
    //al_draw_filled_rectangle(0 + 10, BUFFER_H/4 + 10, BUFFER_W - 10, BUFFER_H - BUFFER_H/4 - 10, al_map_rgb(9, 9, 9));
    } else {
        lost = false;
        *play = 2;
    }
    al_draw_text(font_title, al_map_rgb(215, 215, 215), BUFFER_W/2, BUFFER_H/2 - 18, ALLEGRO_ALIGN_CENTRE, "Você não conseguiu se");
    al_draw_text(font_title, al_map_rgb(215, 215, 215), BUFFER_W/2, BUFFER_H/2 + 6, ALLEGRO_ALIGN_CENTRE, "demostrar resistente");

    //al_draw_textf(font, al_map_rgb(155, 155, 155), BUFFER_W/2, 400, ALLEGRO_ALIGN_CENTRE, "Hello world!%d - %d", BUFFER_W, BUFFER_H);

    return;
}


typedef struct ENEMY {
    float x, y;
    int height;
    int width;
} ENEMY;
ENEMY enemy;


void init_enemy(void) {
    enemy.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    enemy.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    enemy.height = 10;
    enemy.width = 10;

    return;
}


void enemy_update(int play_x, int play_y) {
    if(tic_tac > 5 && tic_tac % 4) {
        if(enemy.x > play_x)
            enemy.x--;
        else if(enemy.x < play_x)
            enemy.x++;
        
        if(enemy.y > play_y)
            enemy.y--;
        else if(enemy.y < play_y)  
            enemy.y++;
    }
    return;
}


void enemy_king_update(int play_x, int play_y) {
    if(tic_tac > 5) {
        if(enemy.x > play_x)
            enemy.x++;
        else if(enemy.x < play_x)
            enemy.x--;
            
        if(enemy.y > play_y)
            enemy.y++;
        else if(enemy.y < play_y)  
            enemy.y--;
    }
}


void enemy_draw(void) {
    al_draw_filled_rectangle(enemy.x, enemy.y, enemy.x + enemy.height, enemy.y + enemy.width, al_map_rgb(255, 255, 255));

    return;
}


#define PARALLEL_PROTAGONIST_W 10
#define PARALLEL_PROTAGONIST_H 10
#define PARALLEL_PROTAGONIST_SPEED 4
#define PARALLEL_PROTAGONIST_MAX_X (BUFFER_W - PARALLEL_PROTAGONIST_W)
#define PARALLEL_PROTAGONIST_MAX_Y (BUFFER_H - PARALLEL_PROTAGONIST_H)

typedef struct PARALLEL_PLAYER {
    int x, y;
    int width;
    int height;
    bool lost;
    bool bishop_done;
    bool tower_done;
    bool knight_done;
    bool king_done;
} PARALLEL_PLAYER;
PARALLEL_PLAYER parallel_player;

void init_parallel_bool(void) {
    parallel_player.bishop_done = false;
    parallel_player.tower_done = false;
    parallel_player.knight_done = false;
    parallel_player.king_done = false;
    
    return;
}


void init_parallel_player(void) {
    parallel_player.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    parallel_player.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2) + 50;
    parallel_player.lost = false;
    parallel_player.width = PROTAGONIST_W;
    parallel_player.height = PROTAGONIST_H;
    
    count_timer = 0;

    return;
}


bool col_enemy;
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

    col_enemy = collision(parallel_player.x, parallel_player.y, enemy.x, enemy.y, enemy.width, enemy.height, PARALLEL_PROTAGONIST_W, PARALLEL_PROTAGONIST_H);
    collision_reaction(col_enemy, &parallel_player.x, &parallel_player.y, enemy.x, enemy.y, enemy.width, enemy.height, PARALLEL_PROTAGONIST_W, PARALLEL_PROTAGONIST_H, PARALLEL_PROTAGONIST_SPEED);

    return;
}


void parallel_player_draw(void) {
    al_draw_filled_rectangle(parallel_player.x, parallel_player.y, parallel_player.x + PARALLEL_PROTAGONIST_W, parallel_player.y + PARALLEL_PROTAGONIST_H, al_map_rgb(255, 255, 255));

    return;
}


typedef struct SHOT {
    int x, y;
    int speed;
    float size;
    bool used;
} SHOT;

#define SHOTS_N 98
SHOT shots[SHOTS_N];
SHOT shots_player[SHOTS_N];


void init_shot(void) {
    for(int i = 0; i < SHOTS_N; i++) {
        shots[i].speed = 1;
        shots[i].used = false;
        shots[i].size = 2.2;
    }
    printf("inicializado\n");

    return;
}


void init_shot_player(void) {
    for(int i = 0; i < SHOTS_N; i++) {
        shots_player[i].speed = 1;
        shots_player[i].used = false;
        shots_player[i].size = 2.2;
    }   
    printf("inicializado\n");

    return;
}


int timing = 0;
void add_shot_tower(void) {
    if(!(timing % 40)) {
        for(int i = 0; i < SHOTS_N - 3; i += 4) {
            if(!shots[i].used && !shots[i+1].used && !shots[i+2].used && !shots[i+3].used) {
                shots[i].x = enemy.x + enemy.width/2;
                shots[i].y = enemy.y + enemy.height;
                shots[i].used = true;

                shots[i+1].x = enemy.x + enemy.width/2;
                shots[i+1].y = enemy.y;
                shots[i+1].used = true;

                shots[i+2].x = enemy.x + enemy.width;
                shots[i+2].y = enemy.y + enemy.height/2;
                shots[i+2].used = true;

                shots[i+3].x = enemy.x;
                shots[i+3].y = enemy.y + enemy.height/2;
                shots[i+3].used = true;

                break;
            }
        }
    }

    return;
}


void add_shot_bishop(void) {
    if(!(timing % 40)) {
        for(int i = 0; i < SHOTS_N - 3; i += 4) {
            if(!shots[i].used && !shots[i+1].used && !shots[i+2].used && !shots[i+3].used) {
                shots[i].x = enemy.x + enemy.width;
                shots[i].y = enemy.y + enemy.height;
                shots[i].used = true;

                shots[i+1].x = enemy.x;
                shots[i+1].y = enemy.y;
                shots[i+1].used = true;

                shots[i+2].x = enemy.x + enemy.width;
                shots[i+2].y = enemy.y + shots[i].size;
                shots[i+2].used = true;

                shots[i+3].x = enemy.x;
                shots[i+3].y = enemy.y + enemy.height;
                shots[i+3].used = true;

                break;
            }
        }
    }

    return;
}


void add_shot(int each) {
    timing++;
    if(each == 2 || each == 1 && tic_tac < 5)
        add_shot_tower();
    else if(each == 3)
        add_shot_bishop();

    return;
}


void add_shot_player(void) {
    timing++;
    if(!(timing % 4)) {
        for(int i = 0; i < SHOTS_N - 7; i += 8) {
            if(!shots_player[i].used && !shots_player[i+1].used && !shots_player[i+2].used && !shots_player[i+3].used &&
               !shots_player[i+4].used && !shots_player[i+5].used && !shots_player[i+6].used && !shots_player[i+7].used) {

                shots_player[i].x = parallel_player.x + parallel_player.width/2;
                shots_player[i].y = parallel_player.y + parallel_player.height;
                shots_player[i].used = true;

                shots_player[i+1].x = parallel_player.x + parallel_player.width/2;
                shots_player[i+1].y = parallel_player.y;
                shots_player[i+1].used = true;

                shots_player[i+2].x = parallel_player.x + parallel_player.width;
                shots_player[i+2].y = parallel_player.y + parallel_player.height/2;
                shots_player[i+2].used = true;

                shots_player[i+3].x = parallel_player.x;
                shots_player[i+3].y = parallel_player.y + parallel_player.height/2;
                shots_player[i+3].used = true;

                shots_player[i+4].x = parallel_player.x + parallel_player.width;
                shots_player[i+4].y = parallel_player.y + parallel_player.height;
                shots_player[i+4].used = true;

                shots_player[i+5].x = parallel_player.x;
                shots_player[i+5].y = parallel_player.y;
                shots_player[i+5].used = true;

                shots_player[i+6].x = parallel_player.x + parallel_player.width;
                shots_player[i+6].y = parallel_player.y + shots_player[i].size;
                shots_player[i+6].used = true;

                shots_player[i+7].x = parallel_player.x;
                shots_player[i+7].y = parallel_player.y + parallel_player.height;
                shots_player[i+7].used = true;

                break;
            }
        }    
    }

    return;
}


bool col_shot;
void shot_collision(SHOT *shot, int play_x, int play_y, int x, int y, int width, int height) {
    col_shot = collision(play_x, play_y, x, y, width, height, PARALLEL_PROTAGONIST_W, PARALLEL_PROTAGONIST_H);
    if(col_shot) { 
        shot->used = false;
        parallel_player.lost = true;
    }

    return;
}


void shot_collision_player(SHOT *shot, int play_x, int play_y, int x, int y, int width, int height) {
    col_shot = collision(play_x, play_y, x, y, width, height, enemy.width, enemy.height);
    if(col_shot) { 
        printf("acertou\n");
    }

    return;
}


void shot_update_tower(int i) {
    shots[i].y += shots[i].speed;
    shots[i+1].y -= shots[i].speed;
    shots[i+2].x += shots[i].speed;
    shots[i+3].x -= shots[i].speed;

    return;
}


void shot_update_bishop(int i) {
    shots[i].y += shots[i].speed;
    shots[i].x += shots[i].speed;
    shots[i+1].y -= shots[i].speed;
    shots[i+1].x -= shots[i].speed;
    shots[i+2].x += shots[i].speed;
    shots[i+2].y -= shots[i].speed;
    shots[i+3].x -= shots[i].speed;
    shots[i+3].y += shots[i].speed;

    return;
}


void shot_update(int each) {
    for(int i = 0; i < SHOTS_N - 3; i += 4) {
        if(shots[i].used || shots[i+1].used || shots[i+2].used || shots[i+3].used) {
            if(each == 2 || each == 1 && tic_tac < 5)
                shot_update_tower(i);
            else if(each == 3)
                shot_update_bishop(i);

            if(each != 1) {
                if(shots[i].y > BUFFER_H)
                shots[i].used = false;
                else if(shots[i+1].y < 0)
                    shots[i+1].used = false;
                else if(shots[i+2].x > BUFFER_W)
                    shots[i+2].used = false;
                else if(shots[i+3].x < 0)
                    shots[i+3].used = false;
            } else {
                if(shots[i].y > enemy.y + enemy.height + 8)
                shots[i].used = false;
                if(shots[i+1].y < enemy.y - 8)
                    shots[i+1].used = false;
                if(shots[i+2].x > enemy.x + enemy.width + 8)
                    shots[i+2].used = false;
                if(shots[i+3].x < enemy.x - 8)
                    shots[i+3].used = false;
            }
            
            for(int n = 0; n < 4; n++)
                if(shots[i+n].used)
                    shot_collision(&shots[i+n], parallel_player.x, parallel_player.y, shots[i+n].x, shots[i+n].y, shots[i+n].size, shots[i+n].size);
        }
    }

    return;
}


void shot_update_player(void) {
    for(int i = 0; i < SHOTS_N - 7; i += 8) {
        if(shots_player[i].used || shots_player[i+1].used || shots_player[i+2].used || shots_player[i+3].used ||
           shots_player[i+4].used || shots_player[i+5].used || shots_player[i+6].used || shots_player[i+7].used) {

            shots_player[i].y += shots_player[i].speed;
            shots_player[i+1].y -= shots_player[i].speed;
            shots_player[i+2].x += shots_player[i].speed;
            shots_player[i+3].x -= shots_player[i].speed;
    
            shots_player[i+4].y += shots_player[i].speed;
            shots_player[i+4].x += shots_player[i].speed;
            shots_player[i+5].y -= shots_player[i].speed;
            shots_player[i+5].x -= shots_player[i].speed;
            shots_player[i+6].x += shots_player[i].speed;
            shots_player[i+6].y -= shots_player[i].speed;
            shots_player[i+7].x -= shots_player[i].speed;
            shots_player[i+7].y += shots_player[i].speed;

            if(shots_player[i].y > BUFFER_H)
                shots_player[i].used = false;
            if(shots_player[i+1].y < 0)
                shots_player[i+1].used = false;
            if(shots_player[i+2].x > BUFFER_W)
                shots_player[i+2].used = false;
            if(shots_player[i+3].x < 0)
                shots_player[i+3].used = false;
            if(shots_player[i+4].y > BUFFER_H)
                shots_player[i+4].used = false;
            if(shots_player[i+5].y < 0)
                shots_player[i+5].used = false;
            if(shots_player[i+6].x > BUFFER_W)
                shots_player[i+6].used = false;
            if(shots_player[i+7].x < 0)
                shots_player[i+7].used = false;

            
            for(int n = 0; n < 8; n++) {
                if(shots_player[i+n].used)
                    shot_collision_player(&shots_player[i+n], enemy.x, enemy.y, shots_player[i+n].x, shots_player[i+n].y, shots_player[i+n].size, shots_player[i+n].size);
            }
        }
    }

    return;
}


void shot_draw(void) {
    for(int i = 0; i < SHOTS_N; i++) {
        if(shots[i].used) {            
            al_draw_filled_circle(shots[i].x, shots[i].y, shots[i].size, al_map_rgb(255, 255, 255));
        }
    }

    return;
}


void shot_draw_player(void) {
    for(int i = 0; i < SHOTS_N; i++) {
        if(shots_player[i].used) {            
            al_draw_filled_circle(shots_player[i].x + 2, shots_player[i].y + 2, shots_player[i].size, al_map_rgb(255, 255, 255));
        }
    }

    return;
}

int oi = 0;
void knight_update(int *play, int *which) {
    tic_tac = time_count();

    if(count_timer > 1) {
        knight_script(&parallel_player.knight_done, which, play);
        restart_time();
    }
    
    return;
}


void bishop_update(int *play) {
    tic_tac = time_count();
    //printf("\n%d", tic_tac);
    if(tic_tac > 15) {
       // printf("\nvenceu");
       parallel_player.bishop_done = true;
       *play = 2;
    } else if(parallel_player.lost) {
        restart_time();
        *play = 7;
    }
    
    return;
}


void tower_update(int *play) {
    tic_tac = time_count();
    //printf("\n%d", tic_tac);
    if(tic_tac > 15) {
       // printf("\nvenceu");
       parallel_player.tower_done = true;
       *play = 2;
    } else if(parallel_player.lost) {
        restart_time();
        *play = 7;
    }
    
    return;
}


void king_update(int *play) {
    tic_tac = time_count();
    //printf("\n%d", tic_tac);
    if(tic_tac > 15) {
       // printf("\nvenceu");
       parallel_player.king_done = true;
       *play = 2;
    } else if(parallel_player.lost) {
        restart_time();
        *play = 7;
    }
    
    return;
}


#endif