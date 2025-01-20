NAME = fractol
CC = cc -g
CCFLAGS = #Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_DIR = libft

SRC =	src/main.c src/utils.c src/ft_mlx_pixel_put.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)/ all
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -c $< -o $@

# -03 -c
clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re