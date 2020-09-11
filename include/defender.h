/*
** EPITECH PROJECT, 2020
** epi
** File description:
** include
*/

#ifndef _DEFENDER_H_
#define _DEFENDER_H_
#include "my.h"
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <SFML/Graphics/Rect.h>
#include "cursor.h"
#include "music.h"
#include "entity.h"
#include "hud.h"
#include "scene.h"
#include "score.h"
#include "hud.h"
#include "core.h"
#include "button.h"
#include "hud.h"
#include "enemy.h"
#include "tower.h"
#include "base.h"
#include "player.h"
#include "../toCopyLIGHT/include/light.h"
#define ENEMY_MAX 50 /* This constant defines the number max of enemies */
#define TOWER_1 49 /* This constant defines the number max of of towers1 */
#define TOWER_2 49 /* This constant defines the number max of of towers1 */
#define TOWER2 game->tower2
/*
** game object calling all the substructures of the project
*/
typedef struct game_s {
    sfEvent *event;
    entity_t **map;
    entity_t **menu;
    entity_t **button;
    scene_t *scene;
    enemy_t **enemy;
    hud_t **hud;
    music_t *music;
    text_t **text;
    tower_t **tower;
    tower_t **tower2;
    entity_t **particle;
    tower_t **tower3;
    core_t *core;
    base_t *base;
    cursor_t *cursor;
    player_t *player;
} game_t;
/*
** game object calling all the substructures of the project
*/

/*
** game initialization
*/
game_t *init_game(void);
base_t *set_base(void);
core_t *set_window(void);
tower_t **set_tower(void);
enemy_t **set_enemy(void);
hud_t **set_hud(void);
tower_t **set_tower2(void);
music_t *init_music(void);
cursor_t *set_cursor(void);
scene_t *set_scene(void);
entity_t **set_button(void);
entity_t **set_map(void);
entity_t **particle(void);
entity_t **set_particle(void);
player_t *set_player(void);
sfIntRect set_tower3_rect(void);
sfIntRect rect3(void);
/*
** game initialization
*/

/*
** scene functions
*/
void manage_pause(game_t *game);
void change_main_menu_scenes(game_t *game, sfVector2i click_position);
int change_scenes(game_t *game, sfVector2i click_position);
void manage_scene(game_t *game);
void change_tutorial_menu_scenes(game_t *game, sfVector2i click_position);
void draw_tutorial(game_t *game);
void change_end_menu_scenes(game_t *game, sfVector2i click_position);
void update_end_but_state(game_t *game);
void update_end_rect(game_t *game);
void initial_end_rect(game_t *game);
/*
** scene functions
*/

/*
** enemies functions
*/
void rand_ene_pos(enemy_t *enemy, game_t *game);
void set_enemy_pos(enemy_t *enemy, game_t *game);
void spawn_enemy(game_t *game);
void enemy_move(enemy_t *enemy, game_t *game);
void enemy_anim(enemy_t *enemy);
/*
** enemies functions
*/

/*
** towers functions
*/
float check_tower_range(enemy_t *enemy, tower_t *tower);
void thunder_anim(entity_t *t);
void set_tower_texture(tower_t **tower, int i);
sfIntRect set_tower_rect(void);
sfIntRect set_tower2_rect(void);
sfIntRect rect(void);
/*
** towers functions
*/

/*
** turret functions
*/
void spawn_turret3(game_t *game);
void spawn_turret(game_t *game);
void turret_attack(game_t *game);
void spawn_turret2(game_t *game);
void turret2_attack_anim(enemy_t *e, game_t *game, int i);
void turret_attack2(game_t *game, tower_t *t, int i);
/*
** turret functions
*/

/*
** hud functions
*/
//void init_tower_buttons(hud_t *hud);
void draw_score(game_t *game);
void draw_best_score(game_t *game);
char *update_best_score(char *buff, game_t *game);
char *get_file(char *path);
/*
** hud functions
*/

/*
** buttons functions
*/
void create_sprite_buttons(game_t *game);
void init_button_position(game_t *game);
void init_button_rectangles(entity_t **button);
void initial_rect(game_t *game);
void set_rect_button(entity_t **button);
void update_but_state(game_t *game);
void update_button_rect(game_t *game);
void update_menu_but_state(game_t *game);
void update_menu_rect(game_t *game);
void initial_menu_rect(game_t *game);
/*
** buttons functions
*/

/*
** main loop functions
*/
int main_loop(void);
int game_input(game_t *game);
void game_display(game_t *game);
void game_event(game_t *game);
void hb_base(enemy_t *enemy);
void draw_menu(game_t *game);
void check_mouse_position(game_t *game, sfVector2i click_position);
bool pos_verif(game_t *game);
/*
** main loop functions
*/

/*
** destroy game functions
*/
void destroy_enemies(game_t *game);
void destroy_buttons(game_t *game);
void destroy_towers(game_t *game);
void destroy_core(game_t *game);
void destroy_particles(game_t *game);
void destroy_game(game_t *game);
/*
** destroy game functions
*/

/*
** Reset game functions
*/
void reset_base(game_t *game);
void reset_enemy(game_t *game);
void reset_game(game_t *game);
void reset_tower(game_t *game);
void reset_particle(game_t *game);
/*
** Reset game functions
*/
float check_tower_range(enemy_t *enemy, tower_t *tower);
void turret2_attack_anim(enemy_t *e, game_t *g, int i);
void anim_turret22(tower_t *t);
void base_life(game_t *game);
void draw_hud(game_t *game);
bool ivl(float number, float interval);
void game_difficulty(game_t *game);
void player_anim(game_t *game);
void player_halo_anim(game_t *game);
void player_move(game_t *game);
float check_player_range(enemy_t *enemy, player_t *player);
#endif
