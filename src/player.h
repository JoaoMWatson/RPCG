#ifndef PLAYER
#define PLAYER

#define PROTAGONIST_W 10
#define PROTAGONIST_H 10

#define PROTAGONIST_SPEED 2
#define PROTAGONIST_MAX_X (BUFFER_W - PROTAGONIST_W)
#define PROTAGONIST_MAX_Y (BUFFER_H - PROTAGONIST_H)

typedef struct PROTAGONIST {
    int x, y;
    int position_x, position_y;
} PROTAGONIST;
PROTAGONIST player;


void init_player(void) {
    player.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    player.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    player.position_x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    player.position_y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);

    return;
}


void player_update(void)
{
    if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A])
        player.position_x -= PROTAGONIST_SPEED;
    else if(key[ALLEGRO_KEY_RIGHT] || key[ALLEGRO_KEY_D])
        player.position_x += PROTAGONIST_SPEED;
    else if(key[ALLEGRO_KEY_UP] || key[ALLEGRO_KEY_W])
        player.position_y -= PROTAGONIST_SPEED;
    else if(key[ALLEGRO_KEY_DOWN] || key[ALLEGRO_KEY_S])
        player.position_y += PROTAGONIST_SPEED;

    /*
    if(player.x < 0)
        player.x = 0;
    if(player.y < 0)
        player.y = 0;
   
    if(player.x > PROTAGONIST_MAX_X)
        player.x = PROTAGONIST_MAX_X;
    if(player.y > PROTAGONIST_MAX_Y)
        player.y = PROTAGONIST_MAX_Y;
    */

    return;
}


void player_draw(void)
{
    al_draw_filled_rectangle(player.x, player.y, player.x + 10, player.y + 10, al_map_rgb(255, 0, 0));
    
    return;
}

#endif