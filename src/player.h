#ifndef PLAYER
#define PLAYER

#define PROTAGONIST_W 10
#define PROTAGONIST_H 10

#define PROTAGONIST_SPEED 2

typedef struct PROTAGONIST {
    int x, y;
    int position_x, position_y;
    int knight;
    int bishop;
    int tower;
    int king;
    ALLEGRO_BITMAP *sprite;
} PROTAGONIST;
PROTAGONIST player;


void init_player(void) {
    player.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    player.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    player.position_x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    player.position_y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    player.knight = 0;
    player.bishop = 0;
    player.tower = 0;
    player.king = 0;

    player.sprite = al_load_bitmap("src/images/pawn.png");
    must_init(true, player.sprite, "player sprite");

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

    return;
}


void player_draw(void)
{
    al_draw_filled_rectangle(player.x, player.y, player.x + PROTAGONIST_W, player.y + PROTAGONIST_H, al_map_rgb(255, 0, 0));
    
    return;
}


void destroy_player(void) {
    al_destroy_bitmap(player.sprite);

    return;
}

#endif