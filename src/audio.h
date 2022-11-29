#ifndef AUDIO
#define AUDIO

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

ALLEGRO_SAMPLE *main_audio = NULL;
ALLEGRO_SAMPLE *mini_game_audio = NULL;
ALLEGRO_SAMPLE *damage = NULL;
ALLEGRO_SAMPLE *movement = NULL;
ALLEGRO_SAMPLE *menu_audio = NULL;
ALLEGRO_SAMPLE *horse_game_audio = NULL;
ALLEGRO_SAMPLE *bishop_game_audio = NULL;
ALLEGRO_SAMPLE *final_boss_game_audio = NULL;

ALLEGRO_SAMPLE_INSTANCE *menu_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *main_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *mini_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *movement_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *horse_game_audio_instace = NULL;
ALLEGRO_SAMPLE_INSTANCE *bishop_game_audio_instance = NULL;
ALLEGRO_SAMPLE_INSTANCE *final_boss_game_audio_instance = NULL;


//------MENU AUDIO------//

void start_menu_audio(void){
    menu_audio = al_load_sample("src/audio/start_menu.ogg");
    menu_audio_instance = al_create_sample_instance(menu_audio);

    al_attach_sample_instance_to_mixer(menu_audio_instance, al_get_default_mixer());
    al_set_sample_instance_gain(menu_audio_instance, 0.04);   
}

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

//------AUDIO MINIGAME HORSE------//

void horse_audio(void){
    horse_game_audio = al_load_sample("src/audio/horse_audio.ogg");
    horse_game_audio_instace = al_create_sample_instance(horse_game_audio);
    al_set_sample_instance_playmode(horse_game_audio_instace , ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(horse_game_audio_instace , al_get_default_mixer());
    al_set_sample_instance_gain(horse_game_audio_instace , 0.018);   
}
//------AUDIO MINIGAME BISHOP------//

void bishop_audio(void){

    bishop_game_audio = al_load_sample("src/audio/bishop_theme.ogg");
    bishop_game_audio_instance  = al_create_sample_instance(bishop_game_audio);
    al_set_sample_instance_playmode(bishop_game_audio_instance  ,ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(bishop_game_audio_instance , al_get_default_mixer());
    al_set_sample_instance_gain(bishop_game_audio_instance , 0.018);   
}

//------AUDIO MINIGAME KING------//

void king_game_audio(void){

    final_boss_game_audio = al_load_sample("src/audio/final_boss.ogg");
    final_boss_game_audio_instance = al_create_sample_instance(final_boss_game_audio);
    al_set_sample_instance_playmode(final_boss_game_audio_instance ,ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(final_boss_game_audio_instance, al_get_default_mixer());
    al_set_sample_instance_gain(final_boss_game_audio_instance , 0.018);
}


//------INIT AUDIOS------//

void init_audio(void){
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
   
}

//------DESTROY AUDIOS------//
void destroy_audios(void){
    al_destroy_sample(menu_audio);
    al_destroy_sample(bishop_game_audio);
    al_destroy_sample(final_boss_game_audio);
    al_destroy_sample(damage);
    al_destroy_sample(movement);
    al_destroy_sample(main_audio);
    al_destroy_sample(mini_game_audio);
    al_destroy_sample(horse_game_audio);

    al_destroy_sample_instance(menu_audio_instance);
    al_destroy_sample_instance(main_game_audio_instance);
    al_destroy_sample_instance(mini_game_audio_instance);
    al_destroy_sample_instance(movement_audio_instance);
    al_destroy_sample_instance(horse_game_audio_instace);
    al_destroy_sample_instance(bishop_game_audio_instance);
    al_destroy_sample_instance(final_boss_game_audio_instance);
}


#endif