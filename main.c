#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h> // writing
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h> // draw 
#include <allegro5/allegro_audio.h> // sounds
#include <allegro5/allegro_acodec.h> // sounds
#include <allegro5/allegro_image.h>

#include "main.h"
#include "src/libraries/structure/structure.c"
#include "src/libraries/player/player.c"
#include "src/libraries/audio/audio.c"
#include "src/libraries/npc/npc.c"
#include "src/libraries/map/map.c"
#include "src/libraries/parallel_game/parallel_game.c"
#include "src/libraries/screenplay/screenplay.c"
#include "src/libraries/stand_screen/stand_screen.c"


void end(void) {
    
    destroy_player();
    destroy_npc();
    destroy_sprites_map();
    destroy_parallel_game();

    return;
}


void start(int *play) {
    *play = MENU;

    init_map();
    init_sprites_map();
    init_script_file();
    init_player(); 
    init_enemy();
    init_parallel_bool();
    init_bool_script();
    init_npc(tile_size);

    return;
}


int main(void)
{
    int play;

    init_structure_all();
    al_set_window_title(display, "[ RPCG ]  Role Playing Chess Game");
    start(&play);


    while(PLAYING) 
    {
        
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                switch (play)
                {
                    case MENU:
                        if(key[ALLEGRO_KEY_ENTER])
                            play = MAIN_GAME;
                        break;

                    case MAIN_GAME:
                        if(!sc_kni.map_it && !sc_bis.map_it && !sc_tow.map_it && !sc_kin.map_it && !sc_map.map_it)
                            player_update();       
                        map_update(&player.position_x, &player.position_y);
                        npc_update(player.position_x, player.position_y, &play);
                        break;
                    
                    case KNIGHT_GAME:
                        knight_update(&play, &player.knight); 
                        break;

                    case BISHOP_GAME:
                        parallel_player_update();
                        enemy_update(parallel_player.x, parallel_player.y);
                        add_shot(BISHOP_BATTLE);
                        shot_update(BISHOP_BATTLE);
                        bishop_update(&play);  
                        break; 

                    case TOWER_GAME:
                        parallel_player_update(); 
                        enemy_update(parallel_player.x, parallel_player.y);
                        add_shot(TOWER_BATTLE);
                        shot_update(TOWER_BATTLE);
                        tower_update(&play);  
                        break;

                    case KING_GAME:
                        parallel_player_update();
                        enemy_king_update(parallel_player.x, parallel_player.y);
                        add_shot(KING_BATTLE);
                        if(key[ALLEGRO_KEY_X] && count_timer%2 == 0)
                            add_shot_player();
                        shot_update(KING_BATTLE);
                        shot_update_player();
                        king_update(&play);  
                        break;

                    case GAME_OVER:
                        break;  

                    case END_GAME:
                        if(parallel_player.king_dead) 
                            player.pawn = 1;
                        else 
                            player.pawn = 0;

                        pawn_script(&player.pawn);

                        if(key[ALLEGRO_KEY_L]) {
                            end();
                            start(&play);
                        }
                        break;                    
                }
                // if(key[ALLEGRO_KEY_M])
                //     play = MAIN_GAME;
                
                if(key[ALLEGRO_KEY_ESCAPE])
                    done = true;
                redraw = true;
      
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        keyboard_update(&event);

        if(redraw && al_is_event_queue_empty(queue))
        {
            switch (play)
            {
                case MENU:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(20,20,20));

                    menu_draw();

                    // audio
                    set_audio(MENU_AUDIO);

                    display_post_draw();
                    break;

                case MAIN_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(20,20,20));

                    map_draw();
                    npc_draw(xOff, yOff);
                    if(sc_kni.map_it)
                        script_draw(sc_kni);
                    else if(sc_bis.map_it)
                        script_draw(sc_bis);
                    else if(sc_tow.map_it)
                        script_draw(sc_tow);
                    else if(sc_kin.map_it)
                        script_draw(sc_kin);
                    else if(sc_map.map_it )
                        script_draw(sc_map); 
                    player_draw(parallel_player.tower_done);

                    // audio
                    set_audio(MAIN_AUDIO);
                   
                    display_post_draw();
                    break;
                
                case KNIGHT_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(20,20,20));

                    script_draw(sc_kni);
                    enemy_draw(KNIGHT_SPRITE);

                    // audio
                    set_audio(HORSE_AUDIO);

                    display_post_draw(); 
                    break;

                case BISHOP_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(20,20,20));

                    parallel_player_draw();
                    enemy_draw(BISHOP_SPRITE);
                    shot_draw();
                    time_draw(tic_tac);

                    // audio
                    set_audio(BISHOP_AUDIO);

                    display_post_draw(); 
                    break; 

                case TOWER_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(20,20,20));

                    parallel_player_draw();
                    enemy_draw(TOWER_SPRITE);
                    shot_draw();
                    time_draw(tic_tac);

                    // audio
                    set_audio(MINI_GAME_AUDIO);

                    display_post_draw(); 
                    break;

                case KING_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(20,20,20));

                    parallel_player_draw();
                    enemy_draw(KING_SPRITE);
                    shot_draw(); 
                    shot_draw_player();
                    if(tic_tac < 6)
                        time_draw(tic_tac);

                    // audio
                    set_audio(KING_AUDIO);

                    display_post_draw(); 
                    break;   

                case GAME_OVER:
                    display_pre_draw();

                    game_over(&parallel_player.lost, &play);

                    display_post_draw(); 
                    break;

                case END_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(32,21,41));

                    if(parallel_player.king_dead)
                        good_ending();
                    else
                        bad_ending();
                    
                    info_return();
                    script_draw(sc_paw);

                    display_post_draw(); 
                    break; 
            }
            
            redraw = false;
        }
        
    }

    destroy_structure_all();
    end();    
    
    return 0;
}