#ifndef MAP
#define MAP

typedef struct SPRITE_MAP 
{
    ALLEGRO_BITMAP* _sheet;

    ALLEGRO_BITMAP* checkered_floor;
    ALLEGRO_BITMAP* left_corner_red_wall;
}SPRITE_MAP;
SPRITE_MAP sprite_map;

/*
const int tile_size = 50;

enum
{
    FLOOR = 0
};
*/


ALLEGRO_BITMAP* grab_sprite_map(int x, int y, int w, int h)
{
    ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(sprite_map._sheet, x, y, w, h);
    must_init(true, sprite, "sprite grab");
    return sprite;
}


void init_sprites_map(void)
{
    sprite_map._sheet = al_load_bitmap("src/images/inside.png");
    must_init(true, sprite_map._sheet, "inside map spritesheet");
    
    if(sprite_map._sheet != NULL)
        sprite_map.checkered_floor = grab_sprite_map(192, 0, 48, 48);

    return;
}

int xOff = 0;
int yOff = 0;
const int map_columns = 10;
const int map_lines = 10;
int tile_size = 48;

int map[10][10] = { 
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                   };

void map_update(void)
{
    if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A])
        xOff += key[ALLEGRO_KEY_LEFT] * 1.3;
    if(key[ALLEGRO_KEY_RIGHT] || key[ALLEGRO_KEY_D])
        xOff -= key[ALLEGRO_KEY_RIGHT] * 1.3;
    if(key[ALLEGRO_KEY_UP] || key[ALLEGRO_KEY_W])
        yOff += key[ALLEGRO_KEY_UP] * 1.3;
    if(key[ALLEGRO_KEY_DOWN] || key[ALLEGRO_KEY_S])
        yOff -= key[ALLEGRO_KEY_DOWN] * 1.3;

    return;
}

void map_draw()
{
    int count = 0;
    for(int i = 0; i < 10; i++)
    {   
        for(int j = 0; j < 10; j++) 
        {
            if(map[i][j] == 1)
            al_draw_bitmap(sprite_map.checkered_floor, xOff + tile_size * (count % 10), yOff + tile_size * (count / 10), 0);   
            count++;
        }    
    }
    return;
}

void destroy_sprites_map(void)
{   
    al_destroy_bitmap(sprite_map.checkered_floor);
    return;
}

#endif