NAME		= cub3D

LIBFT_DIR	= libft

LIBFT 		= $(LIBFT_DIR)/libft.a

SRC			= $(addprefix src/, main.c check_argv.c init.c parse.c map_parse.c map_utils.c free_cub.c check.c \
				print_utils.c check_color.c check_map.c)

OBJ			= $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

RM			= rm -f

OBJ_DIR 	= obj

CFLAGS		= -Wall -Werror -Wextra -I inc/

CC			= gcc

all: make_libft	$(NAME)

$(NAME): $(OBJ) $(LIBFT) inc/cub3D.h
	$(CC) -g $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(OBJ_DIR)/%.o : src/%.c inc/cub3D.h Makefile | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re



