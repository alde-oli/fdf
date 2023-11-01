NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)

OBJS = $(addprefix obj/, $(SRC:.c=.o))

all : $(NAME)

obj/%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean :
	rm -rf obj/

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re