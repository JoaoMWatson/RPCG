#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h> // writing
#include <allegro5/allegro_primitives.h> // draw 
#include <allegro5/allegro_audio.h> // sounds
#include <allegro5/allegro_acodec.h> // sounds
#include <allegro5/allegro_image.h>

#include "src/structure.h"
#include "src/map.h"
#include "src/player.h"


int main()
{
    int playing = 1;

    init_structure_all();
    init_sprites_map();
    init_player();
    al_set_window_title(display, "[ RPCG ]  Role Playing Chess Game");

    /*
    int lines, columns;
    int** map = load_map("organization_map.txt", &lines, &columns);
    must_init(true, map, "map");
    */

    while(playing) 
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                player_update();
                map_update();

                if(key[ALLEGRO_KEY_ESCAPE])
                    done = true;

                redraw = true;
                //frames++;
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
            display_pre_draw();
            al_clear_to_color(al_map_rgb(0,0,0));

            map_draw();
            player_draw();

            display_post_draw();
            redraw = false;
        }
    }

    //destroy_map(map, lines);
    destroy_structure_all();
    destroy_sprites_map();
    
    
    return 0;
}



