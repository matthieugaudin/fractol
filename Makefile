NAME = fractol
CC = cc
CCFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_DIR = libft
MLX = libmlx.a
MLX_DIR = mlx_linux


SRC =	src/main.c src/parsing.c src/init_fractal.c src/draw_fractal.c \
		src/event_handler.c src/free_data.c src/utils.c src/lerping.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) bonus
	@$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CCFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)

%.o: %.c
	$(CC) $(CCFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re