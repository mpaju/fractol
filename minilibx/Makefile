#
#

NOM=libmlx.a
UNAME=LibMLX
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "\033[0;37m$(UNAME) make all done\033[0;38m"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@echo "\033[0;33m$(UNAME) make clean done\033[0;38m"

fclean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app	
	@echo "\033[0;33m$(UNAME) make fclean done\033[0;38m"

re: clean all
