NAME = fdf

CC = cc

CFLAGS = -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lmlx -lXext -lX11

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

libmlx:
	make -C ./mlx

all : $(NAME)

${NAME}: libmlx ${OBJS}
	${CC} -framework OpenGL -framework AppKit -Imlx ${OBJS} -Lmlx -lmlx -o ${NAME}

clean :
	rm -rf $(OBJS)
	make clean -C ./mlx

fclean : clean
	rm -rf $(NAME)
	make clean -C ./mlx
	rm -rf ./mlx

re : fclean all

.PHONY: all clean fclean re