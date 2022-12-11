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
    ALLEGRO_BITMAP* red_wall;
    ALLEGRO_BITMAP* border_top_left;
    ALLEGRO_BITMAP* border_top_right;
    ALLEGRO_BITMAP* border_bottom_left;
    ALLEGRO_BITMAP* border_bottom_right;
    ALLEGRO_BITMAP* door;
    ALLEGRO_BITMAP* flag;
    ALLEGRO_BITMAP* red_flag;
    ALLEGRO_BITMAP* rug_top_left;
    ALLEGRO_BITMAP* rug_top_right;
    ALLEGRO_BITMAP* rug_bottom_left;
    ALLEGRO_BITMAP* rug_bottom_right;
    ALLEGRO_BITMAP* rug_top_center;
    ALLEGRO_BITMAP* rug_bottom_center;
    ALLEGRO_BITMAP* windows;
    ALLEGRO_BITMAP* red_windows;
    
    ALLEGRO_BITMAP* table_bottom_right;
    ALLEGRO_BITMAP* table_bottom_left;
    ALLEGRO_BITMAP* table_bottom;
    ALLEGRO_BITMAP* table_top_right;
    ALLEGRO_BITMAP* table_top_left;
    ALLEGRO_BITMAP* table_top;

    ALLEGRO_BITMAP* torch_center;
    ALLEGRO_BITMAP* torch_left;
    ALLEGRO_BITMAP* blue_torch_center;
    ALLEGRO_BITMAP* blue_torch_left;
    ALLEGRO_BITMAP* red_wall_torch_center;
    ALLEGRO_BITMAP* red_wall_torch_left;
    ALLEGRO_BITMAP* throne;
    ALLEGRO_BITMAP* red_floor;
    ALLEGRO_BITMAP* seat;

    ALLEGRO_BITMAP* book_top;
    ALLEGRO_BITMAP* book_bottom;
    ALLEGRO_BITMAP* bible;
    ALLEGRO_BITMAP* cup_wine;
    ALLEGRO_BITMAP* cup_water;
    ALLEGRO_BITMAP* book;
    ALLEGRO_BITMAP* arrow;
    ALLEGRO_BITMAP* poison;
    ALLEGRO_BITMAP* cross;
    ALLEGRO_BITMAP* all_rug;
    ALLEGRO_BITMAP* border_rug_bottom;
    ALLEGRO_BITMAP* rug_curve;
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
    RED_FLAG = 114,
    RUG_TOP_LEFT = 115,
    RUG_TOP_RIGHT = 116,
    RUG_BOTTOM_LEFT = 117,
    RUG_BOTTOM_RIGHT = 118,
    RUG_TOP_CENTER = 119,
    RUG_BOTTOM_CENTER = 120,
    WINDOWS = 121,
    RED_WINDOWS = 122, 
    TABLE_BOTTOM_RIGHT = 123,
    TABLE_BOTTOM_LEFT = 124,
    TABLE_BOTTOM = 125,
    TABLE_TOP_RIGHT = 126,
    TABLE_TOP_LEFT = 127,
    TABLE_TOP = 128,   
    TORCH_CENTER = 129,
    TORCH_LEFT = 130,
    BLUE_TORCH_CENTER = 131,
    BLUE_TORCH_LEFT = 132,
    RED_WALL_TORCH_CENTER = 133,
    RED_WALL_TORCH_LEFT = 134,
    THRONE = 135,
    RED_FLOOR = 136,
    SEAT = 137,
    BOOK_TOP = 138,
    BOOK_BOTTOM = 139,
    BIBLE = 140,
    CUP_WINE = 141,
    CUP_WATER = 142,
    BOOK = 143,
    ARROW = 144,
    POISON = 145,
    CROSS = 146,
    ALL_RUG = 147,
    BORDER_RUG_BOTTOM = 148,
    RUG_CURVE = 149
};


ALLEGRO_BITMAP* grab_sprite_map(int x, int y, int w, int h, char m[]);

void init_sprites_map(void);

int xOff = 0;
int yOff = 0;
const int map_columns = 48;
const int map_lines = 13;
int tile_size = 32;

FILE* tile_map;  
    
int map[13][48];
void init_map(void);

bool collision(int player_x, int player_y, int x, int y, int width, int height, int play_width, int play_height);

void collision_reaction(bool collision, int *player_position_x, int *player_position_y, int x, int y, int width, int height, int play_width, int play_height, int speed);

void detect_collision(int *player_position_x, int *player_position_y);

void it_table(int min, int max, bool *table);

bool table_horse = false;
bool table_bishop = false;
bool table_tower = false;
void detect_iteration_map(int *player_position_x, int *player_position_y);

void map_update(int *player_position_x, int *player_position_y);

void map_draw(void);

void destroy_sprites_map(void);

#endif