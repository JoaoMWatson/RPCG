#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h> // writing
#include <allegro5/allegro_primitives.h> // draw 
#include <allegro5/allegro_audio.h> // sounds
#include <allegro5/allegro_acodec.h> // sounds
#include <allegro5/allegro_image.h>

#include "src/structure.h"


int main()
{
    int playing = 1;

    init_structure_all();
    al_set_window_title(display, "[ RPCG ]  Role Playing Chess Game");

    while(playing) 
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
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
        {
            break;
        }

        keyboard_update(&event);

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(50, 10, 50));
            al_draw_text(font, al_map_rgb(255, 255, 255), 100, 70, 0, "Hello world!");
            al_flip_display();

            redraw = false;
        }
    }

    destroy_structure_all();
    
    
    return 0;
}



