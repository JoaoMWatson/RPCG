#ifndef AUDIO
#define AUDIO

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_SAMPLE *main_audio = NULL;
ALLEGRO_SAMPLE *mini_game_audio = NULL;
ALLEGRO_SAMPLE *damage = NULL;
ALLEGRO_SAMPLE *movement = NULL;

ALLEGRO_SAMPLE_INSTANCE *main_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *mini_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *movement_audio_instance = NULL;


//------DAMAGE AUDIO------//

void damage_audio(void){
    damage = al_load_sample("src/audio/damage.ogg");
}

 //------MOVEMENT AUDIO------//

 void movement_audio(void){
    movement = al_load_sample("src/audio/footsteps_7.ogg");
    movement_audio_instance = al_create_sample_instance(movement);

    al_attach_sample_instance_to_mixer(movement_audio_instance, al_get_default_mixer());
    al_set_sample_instance_gain(movement_audio_instance, 0.04);
 }

//------AUDIO MAIN------//
void main_game_audio(void){

    main_audio = al_load_sample("src/audio/main_audio.ogg");
    main_game_audio_instance = al_create_sample_instance(main_audio);
    al_set_sample_instance_playmode(main_game_audio_instance, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(main_game_audio_instance, al_get_default_mixer());
    al_set_sample_instance_gain(main_game_audio_instance, 0.02);
}

//------AUDIO MINIGAME------//
void minigame_audio(void){
   
    mini_game_audio = al_load_sample("src/audio/mini_game.ogg");
    mini_game_audio_instance = al_create_sample_instance(mini_game_audio);
    al_set_sample_instance_playmode(mini_game_audio_instance,ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(mini_game_audio_instance,al_get_default_mixer());
    al_set_sample_instance_gain(mini_game_audio_instance, 0.018);
    
}

//------INIT AUDIOS------//

void init_audio(void){
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);

    main_game_audio();
    minigame_audio();
    movement_audio();
   
}

//------DESTROY AUDIOS------//
void destroy_audios(void){

    al_destroy_sample(damage);
    al_destroy_sample(movement);
    al_destroy_sample(main_audio);
    al_destroy_sample(mini_game_audio);
    al_destroy_sample_instance(main_game_audio_instance);
    al_destroy_sample_instance(mini_game_audio_instance);
    al_destroy_sample_instance(movement_audio_instance);
}


#endif