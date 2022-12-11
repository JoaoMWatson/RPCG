#ifndef PARALLEL_GAME
#define PARALLEL_GAME

int count_timer = 0;
int tic_tac;

void restart_time(void);

int time_count(void);

void game_over(bool *lost, int *play);

typedef struct ENEMY {
    float x, y;
    int height;
    int width;
    ALLEGRO_BITMAP *sprite[5];
} ENEMY;
ENEMY enemy;


void init_enemy(void);

void init_enemy_game(void);

void enemy_update(int play_x, int play_y);

void enemy_king_update(int play_x, int play_y);

void enemy_draw(int which);

#define PARALLEL_PROTAGONIST_W 14
#define PARALLEL_PROTAGONIST_H 27
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
    bool king_dead;
    ALLEGRO_BITMAP *sprite;
} PARALLEL_PLAYER;
PARALLEL_PLAYER parallel_player;

void init_parallel_bool(void);

void init_parallel_player(void);

bool col_enemy;
void parallel_player_update(void);

void parallel_player_draw(void);

typedef struct SHOT {
    int x, y;
    int speed;
    float size;
    bool used;
} SHOT;

#define SHOTS_N 98
SHOT shots[SHOTS_N];
SHOT shots_player[SHOTS_N];

void init_shot(void);

void init_shot_player(void);

int timing = 0;
void add_shot_tower(void);

void add_shot_bishop(void);

void add_shot(int each);

void add_shot_player(void);

bool col_shot;
void shot_collision(SHOT *shot, int play_x, int play_y, int x, int y, int width, int height);

void shot_collision_player(SHOT *shot, int play_x, int play_y, int x, int y, int width, int height);

void shot_update_tower(int i);

void shot_update_bishop(int i);

void shot_update(int each);

void shot_update_player(void);

void shot_draw(void);

void shot_draw_player(void);

int time_win = 15;
void time_draw(int time_counting);

void knight_update(int *play, int *which);

void bishop_update(int *play);

void tower_update(int *play);

void king_update(int *play);

void destroy_parallel_game(void);

#endif