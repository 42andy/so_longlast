SRCS = $(wildcard src/*.c) $(wildcard utils/*.c)
GNL = $(wildcard utils/get_next_line/*.c)
PRINTF = utils/ft_printf/libftprintf.a

MLX = utils/mlx/
MLX_LIB = $(MLX)libmlx.a
MLX_FLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

OBJS = $(SRCS:.c=.o) $(GNL:.c=.o)

all: $(PRINTF) $(MLX_LIB) $(NAME)

$(PRINTF) :
	$(MAKE) -C utils/ft_printf

$(MLX_LIB):
	$(MAKE) -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(PRINTF)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C utils/ft_printf clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C utils/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re