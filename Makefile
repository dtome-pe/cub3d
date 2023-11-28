NAME		= cub3D

LIBFT_DIR	= libft

LIBFT 		= $(LIBFT_DIR)/libft.a

MINI_DIR 	= mlx

MINI 		= $(MINI_DIR)/libmlx.a

FILES		= main check_argv init parse parse_map utils_map free_cub check \
			  utils_print check_color check_map check_single check_map_aux game \
			  utils_vector check_textures keys utils_mlx floor_ceiling draw

SRC			= $(addprefix src/, $(addsuffix .c, $(FILES)))

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
