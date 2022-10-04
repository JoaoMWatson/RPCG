#ifndef MAP
#define MAP

typedef struct SPRITE_MAP 
{
    ALLEGRO_BITMAP* _sheet;

    ALLEGRO_BITMAP* checkered_floor;
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

/*
int** load_map(const char* filename, int* lines, int* columns)
{
    FILE* file = fopen(filename, "r");
    int** matriz;

    if(file != NULL)
    {
        fscanf(file, "%d %d", lines, columns);

        matriz = (int**) malloc( (*lines) * sizeof(int*) );

        for(int i = 0; i < *lines; i++)
        {
            for(int j = 0; j < *columns; j++)
            {
                fscanf(file, "%d", &matriz[i][j]);
            }
        }

        fclose(file);
    }

    return matriz;
}


void map_draw(ALLEGRO_BITMAP* buffer, int** map, int lines, int columns)
{
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(map[i][j] == FLOOR)
            al_draw_bitmap(buffer, j * tile_size, i * tile_size, 0);
        }
    }

    return;
}


void destroy_map(int** map, int lines)
{
    for(int i = 0; i < lines; i++)
        free(map[i]);
    
    free(map);

    return;
}
*/

int xOff = 0;
int yOff = 0;
int map_columns = 10;
int map_size = 120;
int tile_size = 48;

int map[] = {
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1
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
    for(int i = 0; i < map_size; i++)
    {
        al_draw_bitmap(sprite_map.checkered_floor, xOff + tile_size * (i % map_columns), yOff + tile_size * (i / map_columns), 0);
    }
    return;
}

void destroy_sprites_map(void)
{   
    al_destroy_bitmap(sprite_map.checkered_floor);
    return;
}

#endif