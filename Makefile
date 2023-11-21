NAME		= cub3D

LIBFT_DIR	= libft

LIBFT 		= $(LIBFT_DIR)/libft.a

MINI_DIR 	= mlx

MINI 		= $(MINI_DIR)/libmlx.a

SRC			= $(addprefix src/, main.c check_argv.c init.c parse.c parse_map.c utils_map.c free_cub.c check.c \
				utils_print.c check_color.c check_map.c check_single.c check_map_aux.c game.c utils_vector.c \
				check_textures.c keys.c utils_mlx.c floor_ceiling.c)

OBJ			= $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

RM			= rm -f

OBJ_DIR 	= obj

CFLAGS		= -Wall -Werror -Wextra -I inc/

MLXFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

FSANITIZE	= -fsanitize=address

CC			= gcc

all: make_libft make_mini $(NAME)

$(NAME): $(OBJ) $(LIBFT) inc/cub3D.h
	$(CC) -g $(CFLAGS) $(OBJ) $(MLXFLAGS) -L$(LIBFT_DIR) -lft -Iinc -o $(NAME)

$(OBJ_DIR)/%.o : src/%.c inc/cub3D.h Makefile | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -Iinc $< -o $@
$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

make_libft:
	@make -C $(LIBFT_DIR)

make_mini:
	@make -C $(MINI_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINI_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(MINI_DIR)

re: fclean all

.PHONY: all clean fclean re
