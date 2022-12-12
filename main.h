bool collision(int player_x, int player_y, int x, int y, int width, int height, int play_width, int play_height);
void collision_reaction(bool collision, int *player_position_x, int *player_position_y, int x, int y, int width, int height, int play_width, int play_height, int speed);

enum play_what
{
    MENU = 0,
    PLAYING = 1,
    MAIN_GAME = 2,
    BISHOP_GAME = 3,
    KING_GAME = 4,
    KNIGHT_GAME = 5,
    TOWER_GAME = 6,
    GAME_OVER = 7,
    END_GAME = 8
};

void end(void);

void start(int *play);

int main(void);