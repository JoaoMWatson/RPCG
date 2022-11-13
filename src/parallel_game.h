#ifndef PARALLEL_GAME
#define PARALLEL_GAME
#include "map.h"

typedef struct ENEMY {
    int x, y;
    int height;
    int width;

    int shot_timer;
} ENEMY;
ENEMY enemy;

void init_enemy(void) {
    enemy.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    enemy.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    enemy.height = 10;
    enemy.width = 10;

    return;
}


void enemy_draw(void) {
    al_draw_filled_rectangle(enemy.x, enemy.y, enemy.x + enemy.height, enemy.y + enemy.width, al_map_rgb(255, 255, 255));

    return;
}


typedef struct SHOT {
    int x, y;
    int speed;
    bool used;
} SHOT;

#define SHOTS_N 200
SHOT shots[SHOTS_N];


void init_shot(void) {
    for(int i = 0; i < SHOTS_N; i++) {
        shots[i].speed = 1;
        shots[i].used = false;
    }

    return;
}

int timing = 0;
void add_shot(void) {
    timing++;
    if(!(timing % 40)) {
        for(int i = 0; i < SHOTS_N - 3; i += 4) {
            if(!shots[i].used) {
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


void shot_update(void) {
    for(int i = 0; i < SHOTS_N - 3; i += 4) {
        if(shots[i].used) {
            shots[i].y += shots[i].speed;
            shots[i+1].y -= shots[i].speed;
            shots[i+2].x += shots[i].speed;
            shots[i+3].x -= shots[i].speed;

            if(shots[i].y > BUFFER_H)
                shots[i].used = false;
            else if(shots[i+1].y < 0)
                shots[i+1].used = false;
            else if(shots[i+2].x > BUFFER_W)
                shots[i+2].used = false;
            else if(shots[i+3].x < 0)
                shots[i+3].used = false;
        }
    }

    return;
}


void shot_draw(void) {
    for(int i = 0; i < SHOTS_N; i++) {
        if(shots[i].used) {
            al_draw_filled_circle(shots[i].x, shots[i].y, 2.2, al_map_rgb(255, 255, 255));
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

    int lives;
    int respawn_timer;
    int invincible_timer;
} PARALLEL_PLAYER;
PARALLEL_PLAYER parallel_player;


void parallel_collision(bool col_enemy) {
    if(col_enemy)
        parallel_player.lives--;

    return;
}


void init_parallel_player(void) {
    parallel_player.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    parallel_player.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2) + 50;
    parallel_player.lives = 3;
    parallel_player.respawn_timer = 0;
    parallel_player.invincible_timer = 120;

    return;
}


bool col_enemy;
void parallel_player_update(void) {
    if(parallel_player.lives < 0)
        return;

    if(parallel_player.respawn_timer)
    {
        parallel_player.respawn_timer--;
        return;
    }

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

    parallel_collision(col_enemy);

    if(parallel_player.invincible_timer) 
        parallel_player.invincible_timer--;
    else {
        
    }

    return;
}


void parallel_player_draw(void) {
    al_draw_filled_rectangle(parallel_player.x, parallel_player.y, parallel_player.x + PARALLEL_PROTAGONIST_W, parallel_player.y + PARALLEL_PROTAGONIST_H, al_map_rgb(255, 255, 255));

    return;
}




#endif