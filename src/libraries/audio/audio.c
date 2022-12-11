#include "audio.h"


void start_audio(ALLEGRO_SAMPLE_INSTANCE *game_audio_instance, float time, bool loop) {
    if(loop)
        al_set_sample_instance_playmode(game_audio_instance, ALLEGRO_PLAYMODE_LOOP);

    al_attach_sample_instance_to_mixer(game_audio_instance, al_get_default_mixer());
    al_set_sample_instance_gain(game_audio_instance, time);    

    return; 
}


void start_menu_audio(void) {
    menu_audio_instance = al_create_sample_instance(al_load_sample("src/audios/start_menu.ogg"));
    start_audio(menu_audio_instance, 0.1, false);
    
    return;
}


void damage_audio(void) {
    damage = al_load_sample("src/audios/damage.ogg");

    return;
}


void movement_audio(void) {
    movement_audio_instance = al_create_sample_instance(al_load_sample("src/audios/footsteps_7.ogg"));
    start_audio(movement_audio_instance, 0.1, false);

    return;
 }


void main_game_audio(void) {
    main_game_audio_instance = al_create_sample_instance(al_load_sample("src/audios/main_audio.ogg"));
    start_audio(main_game_audio_instance, 0.05, true);

    return;
}


void minigame_audio(void) {
    mini_game_audio_instance = al_create_sample_instance(al_load_sample("src/audios/mini_game.ogg"));
    start_audio(mini_game_audio_instance, 0.05, true);
    
    return;
}


void horse_audio(void) {
    horse_game_audio_instace = al_create_sample_instance(al_load_sample("src/audios/horse_audio.ogg"));
    start_audio(horse_game_audio_instace, 0.05, true);

    return;
}


void bishop_audio(void) {
    bishop_game_audio_instance  = al_create_sample_instance(al_load_sample("src/audios/bishop_theme.ogg"));
    start_audio(bishop_game_audio_instance, 0.05, true);

    return;
}


void king_game_audio(void) {
    final_boss_game_audio_instance = al_create_sample_instance(al_load_sample("src/audios/final_boss.ogg"));
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