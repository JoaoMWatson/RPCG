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
    ALLEGRO_BITMAP *sprite_player;
    ALLEGRO_BITMAP* sprite[12];
} PROTAGONIST;
PROTAGONIST player;


ALLEGRO_BITMAP* grab_sprite_player(int x, int y, int w, int h, char m[])
{
    ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(player.sprite_player, x , y, w , h);
    must_init(true, sprite, m);

    return sprite;
}


void init_player(void) {
    player.x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    player.y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    player.position_x = (BUFFER_W / 2) - (PROTAGONIST_W / 2);
    player.position_y = (BUFFER_H / 2) - (PROTAGONIST_H / 2);
    player.knight = 0;
    player.bishop = 0;
    player.tower = 0;
    player.king = 0;

    player.sprite_player = al_load_bitmap("src/images/pawn.png");
    player.sprite[0] = grab_sprite_player(0, 0 , 28, 28, "player 00");
    player.sprite[1] = grab_sprite_player(28, 0 , 28, 28, "player 01");  
    player.sprite[2] = grab_sprite_player(56, 0 , 28, 28, "player 02");
    player.sprite[3] = grab_sprite_player(84, 0 , 28, 28, "player 03");
    player.sprite[4] = grab_sprite_player(112, 0 , 28, 28, "player 04");
    player.sprite[5] = grab_sprite_player(140, 0 , 28, 28, "player 05");
    player.sprite[6] = grab_sprite_player(168, 0 , 28, 28, "player 06");
    player.sprite[7] = grab_sprite_player(196, 0 , 28, 28, "player 07");
    player.sprite[8] = grab_sprite_player(224, 0 , 28, 28, "player 08");
    player.sprite[9] = grab_sprite_player(252, 0 , 28, 28, "player 09");
    player.sprite[10] = grab_sprite_player(280, 0 , 28, 28, "player 10");
    player.sprite[11] = grab_sprite_player(308, 0 , 28, 28, "player 11");

    return;
}


void player_update(void)
{
    if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A]) {
        player.position_x -= PROTAGONIST_SPEED;
        
        if(!(troca_sprite % 2 )) {
            troca_sprite = 0;

            if(posicao < 3 || posicao >= 5) {
                posicao = 3;
            } else if( posicao == 3 || posicao == 4) {
                posicao++;
            }
        }
        // if(player.x - 10  < 0 || player.x + 10 > 0) {
        //     al_play_sample_instance(movement_audio_instance);
        // }
    } 
    else if(key[ALLEGRO_KEY_RIGHT] || key[ALLEGRO_KEY_D]) {
        player.position_x += PROTAGONIST_SPEED;

        if(!(troca_sprite % 2)) {
            troca_sprite = 0;

            if(posicao < 0 || posicao >= 2) {
                posicao = 0;
            } else if( posicao == 0 || posicao == 1) {
                posicao++;
            }
        }
        // if(player.x - 10  < 0 || player.x + 10 > 0) {
        //     al_play_sample_instance(movement_audio_instance);
        // }
    } 
    else if(key[ALLEGRO_KEY_UP] || key[ALLEGRO_KEY_W]) {
        player.position_y -= PROTAGONIST_SPEED;

        if(!(troca_sprite % 2)){
            troca_sprite = 0;

            if(posicao < 6 || posicao >= 8) {
                posicao = 6;
            } else if( posicao == 6 || posicao == 7) {
                posicao++;
            }
        }
        // if(player.y - 10 < 0 || player.y + 10 > 0) {
        //     al_play_sample_instance(movement_audio_instance);
        // } 
    }     
    else if(key[ALLEGRO_KEY_DOWN] || key[ALLEGRO_KEY_S]) {
        player.position_y += PROTAGONIST_SPEED;
        
        if(!(troca_sprite % 2)) {
            troca_sprite = 0;

            if(posicao < 9 || posicao >= 11) {
                posicao = 9;
            } else if( posicao == 9 || posicao == 10) {
                posicao++;
            }
        }
        // if(player.y - 10 < 0 || player.y + 10 > 0) {
        //     al_play_sample_instance(movement_audio_instance);
        // }  
    }

    troca_sprite++;
    return;  

}


void player_draw(void)
{
    //al_draw_filled_rectangle(player.x, player.y, player.x + PROTAGONIST_W, player.y + PROTAGONIST_H, al_map_rgb(255, 0, 0));
    al_draw_bitmap(player.sprite[posicao], player.x - 1, player.y - 18, 0);

    return;
}


void destroy_player(void) {
    al_destroy_bitmap(player.sprite_player);
    al_destroy_bitmap(player.sprite[0]);
    al_destroy_bitmap(player.sprite[1]);
    al_destroy_bitmap(player.sprite[2]);
    al_destroy_bitmap(player.sprite[3]);
    al_destroy_bitmap(player.sprite[4]);
    al_destroy_bitmap(player.sprite[5]);
    al_destroy_bitmap(player.sprite[6]);
    al_destroy_bitmap(player.sprite[7]);
    al_destroy_bitmap(player.sprite[8]);
    al_destroy_bitmap(player.sprite[9]);
    al_destroy_bitmap(player.sprite[10]);
    al_destroy_bitmap(player.sprite[11]);

    return;
}

#endif