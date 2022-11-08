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
        MAIN_GAME,
        BISHOP_GAME,
        KING_GAME,
        PAWN_GAME,
        TOWER_GAME
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
                        npc_update(player.position_x, player.position_y);
                        break;
                    
                    case PAWN_GAME:
                        
                        break;  
                                 
                }
                if(key[ALLEGRO_KEY_P])
                    play = MAIN_GAME;
                if(key[ALLEGRO_KEY_Y])
                    play = PAWN_GAME;

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
            }
            
            redraw = false;
        }
        
    }


    destroy_structure_all();
    destroy_sprites_map();
    
    
    return 0;
}