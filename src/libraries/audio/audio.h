#ifndef AUDIO
#define AUDIO

enum audios {
    MENU_AUDIO, 
    MAIN_AUDIO,
    MINI_GAME_AUDIO,
    HORSE_AUDIO,
    BISHOP_AUDIO,
    KING_AUDIO
};

ALLEGRO_SAMPLE *damage = NULL;

ALLEGRO_SAMPLE_INSTANCE *menu_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *main_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *mini_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *movement_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *horse_game_audio_instace = NULL;
ALLEGRO_SAMPLE_INSTANCE *bishop_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *final_boss_game_audio_instance = NULL;

void start_audio(ALLEGRO_SAMPLE_INSTANCE *game_audio_instance, float time, bool loop);

void start_menu_audio(void);

void damage_audio(void);

void movement_audio(void);

void main_game_audio(void);

void minigame_audio(void);

void horse_audio(void);

void bishop_audio(void);

void king_game_audio(void);

void set_audio(int audio);

void init_audio(void);

void destroy_audios(void);

#endif