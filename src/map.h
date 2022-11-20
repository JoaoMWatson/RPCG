#ifndef MAP
#define MAP
#include "npc.h"

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
    ALLEGRO_BITMAP* red_wall;
    ALLEGRO_BITMAP* border_top_left;
    ALLEGRO_BITMAP* border_top_right;
    ALLEGRO_BITMAP* border_bottom_left;
    ALLEGRO_BITMAP* border_bottom_right;
    ALLEGRO_BITMAP* door;
    ALLEGRO_BITMAP* flag;
    ALLEGRO_BITMAP* torch;
    ALLEGRO_BITMAP* rug_top_left;
    ALLEGRO_BITMAP* rug_top_right;
    ALLEGRO_BITMAP* rug_bottom_left;
    ALLEGRO_BITMAP* rug_bottom_right;
    ALLEGRO_BITMAP* rug_top_center;
    ALLEGRO_BITMAP* rug_bottom_center;
    ALLEGRO_BITMAP* windows;
    ALLEGRO_BITMAP* red_windows;
 

}SPRITE_MAP;
SPRITE_MAP sprite_map;

enum sprite_block
{
    VOIDING = 10,             //vazio
    CORNER_TOP_LEFT = 20,     //canto superior esquerdo
    CORNER_TOP_RIGHT = 30,    // canto superior direito
    CORNER_BOTTOM_LEFT = 40,  // canto inferior esquerdo
    CORNER_BOTTOM_RIGHT = 50, //canto inferior direito
    CORNER_LEFT = 60,         // canto esquerdo
    CORNER_RIGHT = 70,        //canto direito
    CORNER_TOP = 80,          //canto superior
    CORNER_BOTTOM = 90,       //canto inferior
    FLOOR = 100,              //piso
    WALL = 110,                // muro
    RED_WALL = 111,
    BORDER_TOP_LEFT = 25,      //borda superior esquerdo
    BORDER_TOP_RIGHT = 35,     // borda superior direito
    BORDER_BOTTOM_LEFT = 45,   // borda inferior esquerdo
    BORDER_BOTTOM_RIGHT = 55,  // borda inferior direitO
    DOOR = 112,
    FLAG = 113,
    TORCH = 114,
    RUG_TOP_LEFT = 115,
    RUG_TOP_RIGHT = 116,
    RUG_BOTTOM_LEFT = 117,
    RUG_BOTTOM_RIGHT = 118,
    RUG_TOP_CENTER = 119,
    RUG_BOTTOM_CENTER = 120,
    WINDOWS = 121,
    RED_WINDOWS = 122, 
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
        sprite_map.voiding = grab_sprite_map(32, 160, 32, 32);
        sprite_map.corner_top_left = grab_sprite_map(128, 96, 32, 32);
        sprite_map.corner_top_right = grab_sprite_map(96, 96, 32, 32);
        sprite_map.corner_bottom_left = grab_sprite_map(32, 96, 32, 32);
        sprite_map.corner_bottom_right = grab_sprite_map(64, 96, 32, 32);
        sprite_map.corner_left = grab_sprite_map(128, 128, 32, 32);
        sprite_map.corner_right = grab_sprite_map(0, 160, 32, 32);
        sprite_map.corner_top = grab_sprite_map(96, 128, 32, 32);
        sprite_map.corner_bottom = grab_sprite_map(160, 128, 32, 32);
        sprite_map.checkered_floor = grab_sprite_map(0, 0, 32, 32);
        sprite_map.wall = grab_sprite_map(96, 32, 32, 32);
        sprite_map.red_wall = grab_sprite_map(32, 32, 32, 32);
        sprite_map.border_top_left = grab_sprite_map(160, 96, 32, 32);
        sprite_map.border_top_right = grab_sprite_map(64, 128, 32, 32);
        sprite_map.border_bottom_left = grab_sprite_map(0, 128, 32, 32);
        sprite_map.border_bottom_right = grab_sprite_map(32, 128, 32, 32);
        sprite_map.door = grab_sprite_map(0, 96, 32, 32);
        sprite_map.flag = grab_sprite_map(160, 64, 32, 32);
        sprite_map.torch = grab_sprite_map(0, 64, 32, 32);
        sprite_map.rug_top_left = grab_sprite_map(96, 0, 32, 32);
        sprite_map.rug_top_right = grab_sprite_map(160, 0, 32, 32);
        sprite_map.rug_bottom_left= grab_sprite_map(128, 0, 32, 32);
        sprite_map.rug_bottom_right = grab_sprite_map(0, 32, 32, 32);
        sprite_map.rug_top_center= grab_sprite_map(32, 0, 32, 32);
        sprite_map.rug_bottom_center = grab_sprite_map(64, 0, 32, 32);
        sprite_map.windows = grab_sprite_map(128, 32, 32, 32);
        sprite_map.red_windows = grab_sprite_map(160, 32, 32, 32);
        
    }

    return;
}


int xOff = 0;
int yOff = 0;
const int map_columns = 46;
const int map_lines = 12;
int tile_size = 32;


FILE* tile_map;  
    
int map[12][46];
void init_map(void) { 
   
    tile_map = fopen("src/tiles/maping.txt", "r");
    if(tile_map == NULL) {
        fprintf(stderr, "Arquivo não foi aberto\n");
        exit(1);
    }
    
    int cod = 10;
    
    for(int i = 0; i < map_lines; i++) {
        for(int j = 0; j < map_columns; j++) {
            fscanf(tile_map, "%d", &cod);
            map[i][j] = cod;
            // fprintf(stderr, "%d ", cod);
        }
            // fprintf(stderr, "\n");
    }

    fclose(tile_map);

    return;
}


bool collision(int player_x, int player_y, int x, int y, int width, int height, int play_width, int play_height) {
    if(player_x > x + width) return false;
    if(player_x + play_width < x) return false;
    if(player_y > y + height) return false;
    if(player_y + play_height < y) return false;

    return true;
}


void collision_reaction(bool collision, int *player_position_x, int *player_position_y, int x, int y, int width, int height, int play_width, int play_height, int speed) {
    if(collision) {
        if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A] || key[ALLEGRO_KEY_RIGHT] || key[ALLEGRO_KEY_D]) {    
            if(*player_position_x + speed < x + width) {  
                *player_position_x = x - play_width - 1;
            } else if(*player_position_x + speed + play_width > x) {
                *player_position_x = x + width + 1;
            }  
        } else if(key[ALLEGRO_KEY_UP] || key[ALLEGRO_KEY_W] || key[ALLEGRO_KEY_DOWN] || key[ALLEGRO_KEY_S]) {
            if(*player_position_y + speed < y + height) {
                *player_position_y = y - play_height - 1;
            } else if(*player_position_y + speed + play_height > y) {
                *player_position_y = y + height + 1;
            } 
        }
    } 
    
    return;
}


void detect_collision(int *player_position_x, int *player_position_y) 
{
    bool col;
    for(int i = 0; i < map_lines; i++)
    {   
        for(int j = 0; j < map_columns; j++) 
        {
            if(map[i][j] == VOIDING
            || map[i][j] == CORNER_TOP_LEFT 
            || map[i][j] == CORNER_TOP_RIGHT 
            || map[i][j] == CORNER_BOTTOM_RIGHT 
            || map[i][j] == CORNER_BOTTOM_LEFT 
            || map[i][j] == CORNER_TOP 
            || map[i][j] == CORNER_BOTTOM 
            || map[i][j] == WALL
            || map[i][j] == RED_WALL
            || map[i][j] == CORNER_LEFT 
            || map[i][j] == CORNER_RIGHT
            || map[i][j] == BORDER_TOP_LEFT 
            || map[i][j] == BORDER_TOP_RIGHT 
            || map[i][j] == BORDER_BOTTOM_RIGHT 
            || map[i][j] == BORDER_BOTTOM_LEFT
            || map[i][j] == DOOR
            || map[i][j] == FLAG
            || map[i][j] == TORCH 
            || map[i][j] == WINDOWS 
            || map[i][j] == RED_WINDOWS  )
            {
                col = collision(*player_position_x, *player_position_y, j * tile_size, i * tile_size, tile_size, tile_size, PROTAGONIST_W, PROTAGONIST_H);
                collision_reaction(col, player_position_x, player_position_y, j * tile_size, i * tile_size, tile_size, tile_size, PROTAGONIST_W, PROTAGONIST_H, PROTAGONIST_SPEED);
            } 
            else if(j == bishop.position_x && i == bishop.position_y
                 || j == king.position_x && i == king.position_y
                 || j == knight.position_x && i == knight.position_y
                 || j == tower.position_x && i == tower.position_y) 
            {
                col = collision(*player_position_x, *player_position_y, j * tile_size, i * tile_size, common_size, common_size, PROTAGONIST_W, PROTAGONIST_H);
                collision_reaction(col, player_position_x, player_position_y, j * tile_size, i * tile_size, common_size, common_size, PROTAGONIST_W, PROTAGONIST_H, PROTAGONIST_SPEED);
            }
           
            //if(col)
            //   printf("Void - x.%d, y.%d Player - %d, %d Colission - %s\n", j*tile_size, i*tile_size, *player_position_x, *player_position_y, col ? "true" : "false");
                    
        }    
    }

    return;
}


void map_update(int *player_position_x, int *player_position_y)
{
    detect_collision(player_position_x, player_position_y);

    xOff = -(*player_position_x - (BUFFER_W / 2) + (PROTAGONIST_W/2));
    yOff = -(*player_position_y - (BUFFER_H / 2) + (PROTAGONIST_H/2));  

    return;
}


void map_draw()
{
    int count = 0;
    bool col;
    for(int i = 0; i < map_lines; i++)
    {   
        for(int j = 0; j < map_columns; j++) 
        {
            switch (map[i][j])
            {
                case VOIDING:
                    al_draw_bitmap(sprite_map.voiding, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case CORNER_TOP_LEFT:
                   al_draw_bitmap(sprite_map.corner_top_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;
                
                case CORNER_TOP_RIGHT:
                   al_draw_bitmap(sprite_map.corner_top_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case CORNER_BOTTOM_RIGHT:
                    al_draw_bitmap(sprite_map.corner_bottom_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);           
                    break;

                case CORNER_BOTTOM_LEFT:
                    al_draw_bitmap(sprite_map.corner_bottom_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;
                    
                case CORNER_LEFT:
                    al_draw_bitmap(sprite_map.corner_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case CORNER_RIGHT:
                    al_draw_bitmap(sprite_map.corner_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;          

                case CORNER_TOP:
                    al_draw_bitmap(sprite_map.corner_top, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case CORNER_BOTTOM:
                    al_draw_bitmap(sprite_map.corner_bottom, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case FLOOR:
                    al_draw_bitmap(sprite_map.checkered_floor, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);          
                    break;

                case WALL:
                    al_draw_bitmap(sprite_map.wall, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;
                
                case RED_WALL:
                    al_draw_bitmap(sprite_map.red_wall, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case BORDER_TOP_LEFT:
                   al_draw_bitmap(sprite_map.border_top_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;
                
                case BORDER_TOP_RIGHT:
                   al_draw_bitmap(sprite_map.border_top_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case BORDER_BOTTOM_RIGHT:
                    al_draw_bitmap(sprite_map.border_bottom_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);           
                    break;

                case BORDER_BOTTOM_LEFT:
                    al_draw_bitmap(sprite_map.border_bottom_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case DOOR:
                    al_draw_bitmap(sprite_map.door, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case FLAG:
                    al_draw_bitmap(sprite_map.flag, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);          
                    break;

                case TORCH:
                    al_draw_bitmap(sprite_map.torch, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case RUG_TOP_LEFT:
                   al_draw_bitmap(sprite_map.rug_top_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;
                
                case RUG_TOP_RIGHT:
                   al_draw_bitmap(sprite_map.rug_top_right , xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case RUG_BOTTOM_LEFT:
                    al_draw_bitmap(sprite_map.rug_bottom_left, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);           
                    break;
                
                case RUG_BOTTOM_RIGHT :
                   al_draw_bitmap(sprite_map.rug_bottom_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;
                
                case RUG_TOP_CENTER :
                   al_draw_bitmap(sprite_map.rug_top_center, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case RUG_BOTTOM_CENTER :
                    al_draw_bitmap(sprite_map.rug_bottom_center, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);           
                    break;
                case WINDOWS :
                   al_draw_bitmap(sprite_map.windows, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;

                case RED_WINDOWS:
                    al_draw_bitmap(sprite_map.red_windows, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);           
                    break;

                default:
                    break;
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
    al_destroy_bitmap(sprite_map.red_wall);
    al_destroy_bitmap(sprite_map.border_top_left);
    al_destroy_bitmap(sprite_map.border_top_right);
    al_destroy_bitmap(sprite_map.border_bottom_left);
    al_destroy_bitmap(sprite_map.border_bottom_right);
    al_destroy_bitmap(sprite_map.door);
    al_destroy_bitmap(sprite_map.flag);
    al_destroy_bitmap(sprite_map.torch);
    al_destroy_bitmap(sprite_map.rug_top_left);
    al_destroy_bitmap(sprite_map.rug_top_right);
    al_destroy_bitmap(sprite_map.rug_bottom_left);
    al_destroy_bitmap(sprite_map.rug_bottom_right);
    al_destroy_bitmap(sprite_map.rug_top_center);
    al_destroy_bitmap(sprite_map.rug_bottom_center);
    al_destroy_bitmap(sprite_map.windows);
    al_destroy_bitmap(sprite_map.red_windows);


    return;
}

#endif