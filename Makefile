LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	init_game.c \
					game_utils.c \
					get_next_line.c \
					img_draw.c \
					img_init.c \
					key_a.c \
					key_d.c \
					key_w.c \
					key_s.c \
					map_check.c \
					so_long.c \
					map_gen.c \
					map_init_utils.c \
					map_init.c \
					map_update.c \
					map_update_utils.c \
					free_game.c \

SOURCES_DIR		=	src

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

INCLUDES		=	inc

NAME			=	so_long

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -no-pie -g3 -fsanitize=address
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
				$(MAKE) && valgrind ./so_long "maps/map.ber"

norm:
				norminette $(SOURCES) ./inc/so_long.h

.PHONY:			all clean fclean re libft minilibx