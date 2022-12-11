#ifndef PLAYER
#define PLAYER

#define PROTAGONIST_W 26
#define PROTAGONIST_H 10

#define PROTAGONIST_SPEED 2

int posicao = 0;
int troca_sprite = 0;

typedef struct PROTAGONIST {
    int x, y;
    int position_x, position_y;
    int knight;
    int bishop;
    int tower;
    int king;
    int pawn;
    int map;
    ALLEGRO_BITMAP *sprite_player_pawn;
    ALLEGRO_BITMAP* sprite_pawn[12];
    ALLEGRO_BITMAP *sprite_player_queen;
    ALLEGRO_BITMAP* sprite_queen[12];
} PROTAGONIST;
PROTAGONIST player;

ALLEGRO_BITMAP* grab_sprite_player(ALLEGRO_BITMAP *main_sprite, int x, int y, int w, int h, char m[]);

void each_grab_player(ALLEGRO_BITMAP* main_sprite, ALLEGRO_BITMAP* sprite[], char m[]);

void init_player(void);

void movement_effect(int min, int max, int p_position);

void player_update(void);

void player_draw(bool tower_done);

void destroy_player(void);

#endif