#ifndef STRUCTURE
#define STRUCTURE

ALLEGRO_TIMER* timer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* buffer;
ALLEGRO_FONT* font;
ALLEGRO_FONT* font_title;
ALLEGRO_EVENT event;

bool done = false;
bool redraw = true;
bool check = true;


/************* CHECK FUNCTION *************/
bool must_init(bool check, bool test, const char *description);


/************* DISPLAY STUFF *************/
#define BUFFER_W 220
#define BUFFER_H 205

#define DISP_SCALE 3
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

bool init_display(bool check);

void display_pre_draw(void);

void display_post_draw(void);


/************* KEYBOARD STUFF *************/
#define KEY_SEEN     1
#define KEY_RELEASED 2
ALLEGRO_KEYBOARD_STATE *k;
unsigned char key[ALLEGRO_KEY_MAX];
unsigned char key_up[ALLEGRO_KEY_MAX];

void keyboard_init(void);

void keyboard_update(ALLEGRO_EVENT* event);


/************* INITIALIZE *************/
bool init_structure_all(void);

void destroy_structure_all(void);

#endif 