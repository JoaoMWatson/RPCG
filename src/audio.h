#ifndef AUDIO
#define AUDIO

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "structure.h"

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


void start_audio(ALLEGRO_SAMPLE_INSTANCE *game_audio_instance, float time, bool loop) {
    if(loop)
        al_set_sample_instance_playmode(game_audio_instance, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(game_audio_instance, al_get_default_mixer());
    al_set_sample_instance_gain(game_audio_instance, time);    

    return; 
}


//------MENU AUDIO------//
void start_menu_audio(void) {
    menu_audio_instance = al_create_sample_instance(al_load_sample("src/audio/start_menu.ogg"));
    start_audio(menu_audio_instance, 0.1, false);
    
    return;
}

//------DAMAGE AUDIO------//

void damage_audio(void) {
    damage = al_load_sample("src/audio/damage.ogg");

    return;
}

 //------MOVEMENT AUDIO------//

 void movement_audio(void) {
    movement_audio_instance = al_create_sample_instance(al_load_sample("src/audio/footsteps_7.ogg"));
    start_audio(movement_audio_instance, 0.1, false);

    return;
 }

//------AUDIO MAIN------//

void main_game_audio(void) {
    main_game_audio_instance = al_create_sample_instance(al_load_sample("src/audio/main_audio.ogg"));
    start_audio(main_game_audio_instance, 0.05, true);

    return;
}

//------AUDIO MINIGAME------//

void minigame_audio(void) {
    mini_game_audio_instance = al_create_sample_instance(al_load_sample("src/audio/mini_game.ogg"));
    start_audio(mini_game_audio_instance, 0.05, true);
    
    return;
}

//------AUDIO MINIGAME HORSE------//

void horse_audio(void) {
    horse_game_audio_instace = al_create_sample_instance(al_load_sample("src/audio/horse_audio.ogg"));
    start_audio(horse_game_audio_instace, 0.05, true);

    return;
}
//------AUDIO MINIGAME BISHOP------//

void bishop_audio(void) {
    bishop_game_audio_instance  = al_create_sample_instance(al_load_sample("src/audio/bishop_theme.ogg"));
    start_audio(bishop_game_audio_instance, 0.05, true);

    return;
}

//------AUDIO MINIGAME KING------//

void king_game_audio(void) {
    final_boss_game_audio_instance = al_create_sample_instance(al_load_sample("src/audio/final_boss.ogg"));
    start_audio(final_boss_game_audio_instance, 0.05, true);

    return;
}


void set_audio(int audio) {
    

    switch (audio)
    {
        case MENU_AUDIO:
            al_play_sample_instance(menu_audio_instance);
            al_stop_sample_instance(main_game_audio_instance);
            al_stop_sample_instance(mini_game_audio_instance);
            al_stop_sample_instance(horse_game_audio_instace);
            al_stop_sample_instance(bishop_game_audio_instance);
            al_stop_sample_instance(final_boss_game_audio_instance);
            break;

        case MAIN_AUDIO:
            al_play_sample_instance(main_game_audio_instance);
            al_stop_sample_instance(menu_audio_instance);
            al_stop_sample_instance(mini_game_audio_instance);
            al_stop_sample_instance(horse_game_audio_instace);
            al_stop_sample_instance(bishop_game_audio_instance);
            al_stop_sample_instance(final_boss_game_audio_instance);
            break;

        case MINI_GAME_AUDIO:
            al_play_sample_instance(mini_game_audio_instance);
            al_stop_sample_instance(main_game_audio_instance);
            break;

        case HORSE_AUDIO:
            al_play_sample_instance(horse_game_audio_instace);
            al_stop_sample_instance(main_game_audio_instance);
            break;

        case BISHOP_AUDIO:
            al_play_sample_instance(bishop_game_audio_instance);
            al_stop_sample_instance(main_game_audio_instance);
            break;

        case KING_AUDIO:
            al_play_sample_instance(final_boss_game_audio_instance);
            al_stop_sample_instance(menu_audio_instance);
            al_stop_sample_instance(main_game_audio_instance);
            al_stop_sample_instance(mini_game_audio_instance);
            al_stop_sample_instance(horse_game_audio_instace);
            al_stop_sample_instance(bishop_game_audio_instance);
            break;
    }

    return;
}


//------INIT AUDIOS------//

void init_audio(void) {
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);

    start_menu_audio();
    damage_audio();
    main_game_audio();
    minigame_audio();
    movement_audio();
    horse_audio();
    bishop_audio();
    king_game_audio();
   
    return;
}

//------DESTROY AUDIOS------//
void destroy_audios(void) {
    al_destroy_sample(damage);

    al_destroy_sample_instance(menu_audio_instance);
    al_destroy_sample_instance(main_game_audio_instance);
    al_destroy_sample_instance(mini_game_audio_instance);
    al_destroy_sample_instance(movement_audio_instance);
    al_destroy_sample_instance(horse_game_audio_instace);
    al_destroy_sample_instance(bishop_game_audio_instance);
    al_destroy_sample_instance(final_boss_game_audio_instance);

    return;
}


#endif