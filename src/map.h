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


bool collision(int player_x, int player_y, int x, int y, int size, int n) {
    if(player_x > x + size) return false;
    if(player_x + PROTAGONIST_W < x) return false;
    if(player_y > y + size) return false;
    if(player_y + PROTAGONIST_H < y) return false;

    return true;
}


void collision_reaction(bool collision, int *player_position_x, int *player_position_y, int* player_x, int *player_y, int x, int y) {
    int nono = 1;
    if(collision) {
        if(*player_x + PROTAGONIST_W > x) {
            *player_position_x += PROTAGONIST_SPEED;
            //*player_x += nono;
            xOff += PROTAGONIST_W;
        }
    }
    return;
}


void map_collision(int *player_position_x, int *player_position_y, int *player_x, int *player_y) 
{
    bool col;
    for(int i = 0; i < map_lines; i++)
    {   
        for(int j = 0; j < map_columns; j++) 
        {
            switch (map[i][j])
            {
                case VOIDING:

                    col = collision(*player_position_x, *player_position_y, j * tile_size, i * tile_size, tile_size, 10);
                    collision_reaction(col, player_position_x, player_position_y, player_x, player_y, j * tile_size, i * tile_size);
                    break;

                case CORNER_TOP_LEFT:
                    /* code */
                    break;
                
                case CORNER_TOP_RIGHT:
                    /* code */
                    break;

                case CORNER_BOTTOM_RIGHT:
                    
                    break;

                case CORNER_BOTTOM_LEFT:
                    /* code */
                    break;

                case CORNER_LEFT:
                    /* code */
                    break;

                case CORNER_RIGHT:
                    
                    break;          

                case CORNER_TOP:
                    /* code */
                    break;

                case CORNER_BOTTOM:
                    
                    break;

                case WALL:
                    
                    //col = collision(*player_position_x, *player_position_y, j * tile_size, i * tile_size, tile_size);
                    break;

                default:
                    break;
            }

            if(col)
                printf("Void - x.%d, y.%d Player - %d, %d Colission - %s\n", j*tile_size, i*tile_size, *player_position_x, *player_position_y, col ? "true" : "false");
                    
        }    
    }

    return;
}


void map_update(int *player_position_x, int *player_position_y, int *player_x, int *player_y)
{   
    xOff = -(*player_position_x - (BUFFER_W / 2) + (PROTAGONIST_W/2));
    yOff = -(*player_position_y - (BUFFER_H / 2) + (PROTAGONIST_H/2));

    //printf("P(%d, %d) - M(%d, %d)\n", player_x, player_y, xOff, yOff);
    

    return;
}





void map_draw(int *player_position_x, int *player_position_y, int *player_x, int *player_y)
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
                    /* code */
                    break;
                
                case CORNER_TOP_RIGHT:
                    /* code */
                    break;

                case CORNER_BOTTOM_RIGHT:
                    al_draw_bitmap(sprite_map.corner_bottom_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);           
                    break;

                case CORNER_BOTTOM_LEFT:
                    /* code */
                    break;

                case CORNER_LEFT:
                    /* code */
                    break;

                case CORNER_RIGHT:
                    al_draw_bitmap(sprite_map.corner_right, xOff + tile_size * (count % map_columns), yOff + tile_size * (count / map_columns), 0);
                    break;          

                case CORNER_TOP:
                    /* code */
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
    return;
}

#endif