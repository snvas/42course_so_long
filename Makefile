LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	read_map.c \
					build_game.c \
					build_img.c \
					build_map.c \
					game_utils.c \
					img_draw.c \
					move_left.c \
					move_right.c \
					move_up.c \
					move_down.c \
					check_map.c \
					so_long.c \
					map_init_utils.c \
					map_update.c \
					map_update_utils.c \
					free_game.c \
					map_resume.c \
					game_hook.c \

SOURCES_DIR		=	src

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

INCLUDES		=	inc

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

#CFLAGS			=	-Wall -Wextra -Werror -no-pie -g3 -fsanitize=address
CFLAGS			=	-Wall -Wextra -Werror -no-pie -g3
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -I $(INCLUDES) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(RM) $(NAME)

re:				fclean all

run:
				$(MAKE) && ./so_long "maps/map.ber"

runv:
				$(MAKE) && valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long maps/map.ber

runiv:
				$(MAKE) && valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./so_long maps/map.berr

norm:
				norminette $(SOURCES) ./inc/so_long.h

.PHONY:			all clean fclean re libft minilibx