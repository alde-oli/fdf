NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra
MINILIBX_FLAGS	= -lmlx -lXext -lX11

SRC = $(wildcard fcts_*/*.c) $(wildcard get_next_line/*.c) main.c
SRC_BONUS = $(wildcard fcts_*/*.c) $(wildcard get_next_line/*.c) main_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
	
%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

libmlx:
	@make -C ./mlx

all : $(NAME)

bonus: libmlx ${OBJS_BONUS}
	@${CC} -framework OpenGL -framework AppKit -Imlx ${OBJS_BONUS} -Lmlx -lmlx -o ${NAME}

${NAME}: libmlx ${OBJS}
	@${CC} -framework OpenGL -framework AppKit -Imlx ${OBJS} -Lmlx -lmlx -o ${NAME}

clean :
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME)
	@make clean -C ./mlx

re : fclean all

.PHONY: all bonus clean fclean re