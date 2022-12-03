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


ALLEGRO_BITMAP* grab_sprite_player(ALLEGRO_BITMAP *main_sprite, int x, int y, int w, int h, char m[])
{
    ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(main_sprite, x , y, w , h);
    must_init(true, sprite, m);

    return sprite;
}


void each_grab_player(ALLEGRO_BITMAP* main_sprite, ALLEGRO_BITMAP* sprite[], char m[]) {
    for(int i = 0, x = 0; i < 12, x <= 308; i++, x += 28) {
        sprite[i] = grab_sprite_player(main_sprite, x, 0, 28, 28, m);
    }

    return;
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
    player.pawn = 0;
    player.map = 0;

    player.sprite_player_pawn = al_load_bitmap("src/images/pawn.png");
    each_grab_player(player.sprite_player_pawn, player.sprite_pawn, "player pawn");

    player.sprite_player_queen = al_load_bitmap("src/images/queen.png");
    each_grab_player(player.sprite_player_queen, player.sprite_queen, "player queen");

    return;
}


void player_update(void)
{
    if(key[ALLEGRO_KEY_LEFT] || key[ALLEGRO_KEY_A]) {
        player.position_x -= PROTAGONIST_SPEED;
        
        if(!(troca_sprite % 2)) {
            troca_sprite = 0;

            if(posicao < 3 || posicao >= 5) {
                posicao = 3;
            } else if( posicao == 3 || posicao == 4) {
                posicao++;
            }
        }
        if(player.x - 10  < 0 || player.x + 10 > 0) {
            al_play_sample_instance(movement_audio_instance);
        }
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
        if(player.x - 10  < 0 || player.x + 10 > 0) {
            al_play_sample_instance(movement_audio_instance);
        }
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
        if(player.y - 10 < 0 || player.y + 10 > 0) {
            al_play_sample_instance(movement_audio_instance);
        } 
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
        if(player.y - 10 < 0 || player.y + 10 > 0) {
            al_play_sample_instance(movement_audio_instance);
        }  
    }

    troca_sprite++;
    return;  

}


void player_draw(bool tower_done)
{
    //al_draw_filled_rectangle(player.x, player.y, player.x + PROTAGONIST_W, player.y + PROTAGONIST_H, al_map_rgb(255, 0, 0));
    if(!tower_done)
        al_draw_bitmap(player.sprite_pawn[posicao], player.x - 1, player.y - 18, 0);
    else
        al_draw_bitmap(player.sprite_queen[posicao], player.x - 1, player.y - 18, 0);    

    return;
}


void destroy_player(void) {
    al_destroy_bitmap(player.sprite_player_pawn);
    al_destroy_bitmap(player.sprite_player_queen);
    
    for(int i = 0; i < 12; i++) {
        al_destroy_bitmap(player.sprite_pawn[i]);
        al_destroy_bitmap(player.sprite_queen[i]);
    }

    return;
}

#endif