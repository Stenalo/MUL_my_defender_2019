##
## EPITECH PROJECT, 2019
## epi
## File description:
## Makefile
##

NAME		=	my_defender

SRC		=	src/main.c						\
			src/main_loop.c					\
			src/init/init.c					\
			src/init/button.c				\
			src/init/init_tower.c			\
			src/init/map.c					\
			src/init/tower_rect.c			\
			src/init/hud.c					\
			src/init/scene.c				\
			src/init/window.c				\
			src/init/enemy.c				\
			src/init/music.c				\
			src/init/cursor.c				\
			src/init/base.c					\
			src/init/player.c				\
			src/display/display.c			\
			src/display/best_score.c		\
			src/free/free_game.c			\
			src/free/destroy_buttons.c		\
			src/free/destroy_core.c			\
			src/free/destroy_enemies.c		\
			src/free/destroy_particles.c	\
			src/free/destroy_towers.c		\
			src/reset/reset.c				\
			src/input/game_input.c			\
			src/scene/change_scene.c		\
			src/scene/tutorial_scene.c		\
			src/scene/end_scene.c			\
			src/event/spawn_enemy.c			\
			src/event/menu_button_state.c	\
			src/event/end_button_state.c	\
			src/event/anim_enemy.c			\
			src/event/pause.c				\
			src/event/button_state.c		\
			src/event/event_index.c			\
			src/event/spawn_turret.c		\
			src/event/turret_attack.c		\
			src/event/anim_thunder.c		\
			src/event/spawn_turret2.c		\
			src/event/pos_verification.c	\
			src/event/spawn_turret3.c		\
			src/event/norm1.c				\
			src/event/norm2.c				\
			src/event/norm3.c

OBJ		=	$(SRC:%c=%o)

CC		=	gcc

CFLAGS	=	-I./include -W -Wall -Wextra -L./lib/my -lmy -L./toCopyLIGHT -llight -I./toCopyLIGHT/include

LDFLAGS		=	  -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

$(NAME)	:	$(OBJ)
		make -C ./lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

all	:	$(NAME)

clean	:
		rm -f $(OBJ)
		make -C ./lib/my clean


fclean	:	clean
		rm -f $(NAME)
		make -C ./lib/my fclean

debug	:	CFLAGS += -g
debug	:	re

re 	:	fclean all
