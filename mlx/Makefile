#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
MLX_INC = ./mlx_int.h ./mlx_new_window.h ./mlx_opengl.h ./mlx_png.h ./mlx.h
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)

%.o : %.c $(MLX_INC)
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NOM)

re: clean all