NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra
MINILIBX_FLAGS = -lmlx -lXext -lX11
INCLUDES = -I include

SRC = $(wildcard src/*/*.c) $(wildcard src/*.c) $(wildcard get_next_line/*.c)

OBJS = $(SRC:.c=.o)
    
%.o: %.c
	@$(CC) $(CFLAGS) -g -I/usr/include $(INCLUDES) -Imlx_linux -O3 -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -g -Lmlx_linux -lmlx_Linux -L/usr/lib $(INCLUDES) -lXext -lX11 -lm -lz -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
