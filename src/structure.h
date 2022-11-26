#ifndef STRUCTURE
#define STRUCTURE

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* buffer;
ALLEGRO_FONT* font;
ALLEGRO_EVENT event;

bool done = false;
bool redraw = true;
bool check = true;

/************* CHECK FUNCTION *************/
bool must_init(bool check, bool test, const char *description)
{
    if(!test) 
    {
        printf("couldn't initialize %s\n", description);
        return false;
    }
    else
    {
        printf("initialize %s\n", description);
        return true;
    }    
}


/************* DISPLAY STUFF *************/
#define BUFFER_W 200
#define BUFFER_H 250

#define DISP_SCALE 3
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

bool init_display(bool check)
{
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    display = al_create_display(DISP_W, DISP_H); // window size (width x height)
    check = must_init(check, display, "display");
    al_set_window_position(display, DISP_W, DISP_H/4);

    buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
    check = must_init(check, buffer, "bitmap buffer");

    return check;
}


void display_pre_draw(void)
{
    // tells Allegro that we want to draw to our buffer rather than to the screen
    al_set_target_bitmap(buffer);

    return;
}


void display_post_draw(void) {
    // tells Allegro that we want to draw to the screen again
    al_set_target_backbuffer(display);

    // scale up our small buffer to fill the screen
    al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISP_W, DISP_H, 0);

    al_flip_display();

    return;
}


/************* KEYBOARD STUFF *************/
#define KEY_SEEN     1
#define KEY_RELEASED 2
ALLEGRO_KEYBOARD_STATE *k;
unsigned char key[ALLEGRO_KEY_MAX];
unsigned char key_up[ALLEGRO_KEY_MAX];

void keyboard_init(void) 
{
    memset(key, 0, sizeof(key));

    return;
}


void keyboard_update(ALLEGRO_EVENT* event) 
{
    switch(event->type)
    {
        case ALLEGRO_EVENT_TIMER:
            for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                key[i] &= KEY_SEEN;
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            key[event->keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
            key_up[event->keyboard.keycode] = KEY_RELEASED;
            break;
        case ALLEGRO_EVENT_KEY_UP:
            key[event->keyboard.keycode] &= KEY_RELEASED;
            break;
    }

    return;
}


/************* INITIALIZE *************/
bool init_structure_all(void)
{
    bool check = true;

    check = must_init(check, al_init(), "allegro");
    check = must_init(check, al_install_keyboard(), "keyboard");
    check = must_init(check, al_init_primitives_addon(), "primitives");
    check = must_init(check, al_init_image_addon(), "image");
    check = must_init(check, al_init_font_addon(), "font addon");
    check = must_init(check, al_init_ttf_addon(), "ttf addon");

    keyboard_init();

    // smooth the edges of primitives 
    
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    timer = al_create_timer(1.0 / 30.0);
    check = must_init(check, timer, "timer");

    queue = al_create_event_queue();
    check = must_init(check, queue, "queue");

    font = al_load_font("src/fonts/lady.ttf", 12, 2);
    check = must_init(check, font, "font");

    check = init_display(check);

    // reacting to keyboard and display events in addition to the timer we set up earlier
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_start_timer(timer);

    return check;
}


void destroy_structure_all(void)
{
    al_destroy_font(font);
    al_destroy_bitmap(buffer);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return;
}

#endif 