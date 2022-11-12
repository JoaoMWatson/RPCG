#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h> // writing
#include <allegro5/allegro_primitives.h> // draw 
#include <allegro5/allegro_audio.h> // sounds
#include <allegro5/allegro_acodec.h> // sounds
#include <allegro5/allegro_image.h>

#include "src/structure.h"
#include "src/player.h"
#include "src/map.h"
#include "src/npc.h"

enum play_what
    {
        PLAYING = 1,
        MAIN_GAME = 2,
        BISHOP_GAME = 3,
        KING_GAME = 4,
        PAWN_GAME = 5,
        TOWER_GAME = 6
    };

int main()
{
    int play = MAIN_GAME;

    init_structure_all();
    init_map();
    init_sprites_map();
    init_player(); 
    init_npc(tile_size);
    al_set_window_title(display, "[ RPCG ]  Role Playing Chess Game");

    

    while(PLAYING) 
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                switch (play)
                {
                    case MAIN_GAME:
                        player_update();       
                        map_update(&player.position_x, &player.position_y);
                        npc_update(player.position_x, player.position_y, &play);
                        break;
                    
                    case PAWN_GAME:
                        player_update(); 
                        break;

                    case BISHOP_GAME:
                        player_update(); 
                        break; 

                    case TOWER_GAME:
                        player_update(); 
                        break;

                    case KING_GAME:
                        player_update(); 
                        break;                     
                }
                if(key[ALLEGRO_KEY_M])
                    play = MAIN_GAME;
                
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
                case MAIN_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(0,0,0));

                    map_draw();
                    player_draw();
                    npc_draw(xOff, yOff);

                    display_post_draw();
                    break;
                
                case PAWN_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(0,100,0));

                    display_post_draw(); 
                   break;

                case BISHOP_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(0,0,100));

                    display_post_draw(); 
                   break; 

                case TOWER_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(100,0,0));

                    display_post_draw(); 
                   break;

                case KING_GAME:
                    display_pre_draw();
                    al_clear_to_color(al_map_rgb(50,100,50));

                    display_post_draw(); 
                   break;     
            }
            
            redraw = false;
        }
        
    }


    destroy_structure_all();
    destroy_sprites_map();
    
    
    return 0;
}