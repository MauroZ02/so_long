NAME = so_long

MLX_PATH = ./minilibx-linux
LIBFT_PATH = ./libft
MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I/usr/include -I$(MLX_PATH)
CFLAGS = -Wall -Wextra -Werror -g3 -I/usr/include -I$(MLX_PATH)

SRC = main.c\

OBJ = $(SRC:%.c=%.o)
all: $(NAME)
$(NAME): $(OBJ) $(MLX) $ 
	@make all -sC ./libft
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -L$(MLX_PATH) -lX11 -lXext -lm $(LIBFT) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -sC ./libft
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make fclean -sC ./libft
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re

# LIB = ar rcs
# RM = rm -f

# CC = cc

# BLUE   = \033[34m
# RESET  = \033[0m

# CCFLAGS = -Wall -Wextra -Werror -g3

# SRC_DIR = src

# SRC = main.c\

# OBJ = $(SRC:.c=.o)

# INCLUDE = so_long.h

# NAME = so_long

# LIBFTA = libft/libft.a

# all: $(NAME)

# %.o: %.c
# 	@$(CC) $(CCFLAGS) -I/libft/libft.h -I/usr/include -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	@cd libft && make
# 	@$(CC) $(CCFLAGS) $(OBJ) -I./so_long.h -I /libft/libft.h minilibx-linux/libmlx_Linux.a $(LIBFTA) -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
# #	$(CC) $(CFLAGS) $(OBJ) minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz $(LIBFTA) -Ilibft -o $(NAME)
# 	@echo "$(BLUE)        ||>>    $(BLUE)so_long compiled!!    <<||$(RESET)"

# clean:
# 	@$(RM) $(OBJ)
# 	@cd libft && make clean

# fclean:
# 	@$(RM) $(NAME) $(OBJ)
# 	@cd libft && make fclean

# re: fclean all

# .PHONY: all clean fclean re