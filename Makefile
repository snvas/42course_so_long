LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	read_map.c \
					get_window_size.c \
					build_window.c \
					build_img.c \
					check_map.c \
					build_map.c \
					draw_img.c \
					press_key.c \
					hooks_map.c \
					hook_game.c \
					change_position.c \
					move_left.c \
					move_right.c \
					move_up.c \
					move_down.c \
					update_map.c \
					render_map.c \
					free_game.c \
					so_long.c \

SOURCES_DIR		=	./game

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

INCLUDES		=	./includes

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

runval:
				$(MAKE) && valgrind ./so_long maps/map.ber

norm:
				norminette $(SOURCES) ./includes/so_long.h ./libft

.PHONY:			all clean fclean re libft minilibx