#ifndef MAP
#define MAP

typedef struct SPRITE_MAP 
{
    ALLEGRO_BITMAP* _sheet;

    ALLEGRO_BITMAP* checkered_floor;
    ALLEGRO_BITMAP* voiding;
    ALLEGRO_BITMAP* corner_top_left;
    ALLEGRO_BITMAP* corner_top_right;
    ALLEGRO_BITMAP* corner_bottom_left;
    ALLEGRO_BITMAP* corner_bottom_right;
    ALLEGRO_BITMAP* corner_left;
    ALLEGRO_BITMAP* corner_right;
    ALLEGRO_BITMAP* corner_top;
    ALLEGRO_BITMAP* corner_bottom;
    ALLEGRO_BITMAP* floor;
    ALLEGRO_BITMAP* wall;
}SPRITE_MAP;
SPRITE_MAP sprite_map;

enum sprite_block
{
    VOIDING = 10,
    CORNER_TOP_LEFT = 20,
    CORNER_TOP_RIGHT = 30,
    CORNER_BOTTOM_LEFT = 40,
    CORNER_BOTTOM_RIGHT = 50,
    CORNER_LEFT = 60,
    CORNER_RIGHT = 70,
    CORNER_TOP = 80,
    CORNER_BOTTOM = 90,
    FLOOR = 100,
    WALL = 110
};

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
    
    if(sprite_map._sheet != NULL) {
        sprite_map.checkered_floor = grab_sprite_map(64, 0, 32, 32);
        sprite_map.voiding = grab_sprite_map(32, 32, 32, 32);
        sprite_map.corner_bottom_right = grab_sprite_map(96, 64, 32, 32);
        sprite_map.corner_bottom = grab_sprite_map(64, 32, 32, 32);
        sprite_map.corner_right = grab_sprite_map(96, 32, 32, 32);
        sprite_map.wall= grab_sprite_map(0, 32, 32, 32);
    }

    return;
}


int xOff = 0;
int yOff = 0;
const int map_columns = 43;
const int map_lines = 10;
int tile_size = 32;


FILE* tile_map;  
    
int map[10][43];
void init_map(void) { 
   
    tile_map = fopen("src/tiles/maping.txt", "r");
    if(tile_map == NULL) {
        fprintf(stderr, "Arquivo não foi aberto\n");
        exit(1);
    }
    
    int cod = 10;
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 43; j++) {
            fscanf(tile_map, "%d", &cod);
            map[i][j] = cod;
            // fprintf(stderr, "%d ", cod);
        }
            // fprintf(stderr, "\n");
    }

    fclose(tile_map);

    return;
}

#define SPEED 3
void map_update(void)
{
    if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A])
        xOff += key[ALLEGRO_KEY_LEFT] * SPEED;
    if(key[ALLEGRO_KEY_RIGHT] || key[ALLEGRO_KEY_D])
        xOff -= key[ALLEGRO_KEY_RIGHT] * SPEED;
    if(key[ALLEGRO_KEY_UP] || key[ALLEGRO_KEY_W])
        yOff += key[ALLEGRO_KEY_UP] * SPEED;
    if(key[ALLEGRO_KEY_DOWN] || key[ALLEGRO_KEY_S])
        yOff -= key[ALLEGRO_KEY_DOWN] * SPEED;

    return;
}


void map_draw()
{
    int count = 0;
    for(int i = 0; i < map_lines; i++)
    {   
        for(int j = 0; j < map_columns; j++) 
        {
            if(map[i][j] == VOIDING) {
                al_draw_bitmap(sprite_map.voiding, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
            } 
            else if(map[i][j] == CORNER_TOP_LEFT) {

            } 
            else if(map[i][j] == CORNER_TOP_RIGHT) {

            } 
            else if(map[i][j] == CORNER_BOTTOM_LEFT) {

            } 
            else if(map[i][j] == CORNER_BOTTOM_RIGHT) {
                al_draw_bitmap(sprite_map.corner_bottom_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
            } 
            else if(map[i][j] == CORNER_LEFT) {

            } 
            else if(map[i][j] == CORNER_RIGHT) {
                al_draw_bitmap(sprite_map.corner_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
            } 
            else if(map[i][j] == CORNER_TOP) {
                
            } 
            else if(map[i][j] == CORNER_BOTTOM) {
                al_draw_bitmap(sprite_map.corner_bottom, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
            } 
            else if(map[i][j] == FLOOR) {
                al_draw_bitmap(sprite_map.checkered_floor, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
            } 
            else if(map[i][j] == WALL) {
                al_draw_bitmap(sprite_map.wall, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
            }

            count++;
        }    
    }
    return;
}


void destroy_sprites_map(void)
{   
    al_destroy_bitmap(sprite_map.checkered_floor);
    al_destroy_bitmap(sprite_map.voiding);
    al_destroy_bitmap(sprite_map.corner_top_left);
    al_destroy_bitmap(sprite_map.corner_top_right);
    al_destroy_bitmap(sprite_map.corner_bottom_left);
    al_destroy_bitmap(sprite_map.corner_bottom_right);
    al_destroy_bitmap(sprite_map.corner_left);
    al_destroy_bitmap(sprite_map.corner_right);
    al_destroy_bitmap(sprite_map.corner_top);
    al_destroy_bitmap(sprite_map.corner_bottom);
    al_destroy_bitmap(sprite_map.floor);
    al_destroy_bitmap(sprite_map.wall);
    return;
}

#endif