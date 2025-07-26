NAME = so_long

MLX_PATH = ./minilibx-linux
LIBFT_PATH = ./libft
MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I/usr/include -I$(MLX_PATH)
#CFLAGS = -Wall -Wextra -Werror -g -O0

SRC = main.c\
	  render.c\
	  graphics.c\
	  checks.c\
	  readmap.c\

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

# NAME     = so_long

# MLX_PATH  = ./minilibx-linux
# LIBFT_PATH= ./libft
# MLX       = $(MLX_PATH)/libmlx.a
# LIBFT     = $(LIBFT_PATH)/libft.a

# CC        = cc
# CFLAGS    = -Wall -Wextra -Werror -g3 -O1 \
#             -fsanitize=address -fno-omit-frame-pointer \
#             -I/usr/include -I$(MLX_PATH)
# LDFLAGS   = -fsanitize=address

# SRC       = main.c \
#             render.c \
#             graphics.c \
#             checks.c \
#             readmap.c
# OBJ       = $(SRC:%.c=%.o)

# all: $(NAME)

# $(NAME): $(OBJ) $(MLX)
# 	@make -sC $(LIBFT_PATH) all
# 	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) \
# 		-L$(MLX_PATH) -lX11 -lXext -lm $(LDFLAGS) -o $(NAME)

# $(MLX):
# 	$(MAKE) -C $(MLX_PATH)

# %.o: %.c so_long.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -f $(OBJ)
# 	@make -sC $(LIBFT_PATH) clean
# 	$(MAKE) -C $(MLX_PATH) clean

# fclean: clean
# 	rm -f $(NAME)
# 	@make -sC $(LIBFT_PATH) fclean
# 	$(MAKE) -C $(MLX_PATH) clean

# re: fclean all

# .PHONY: all clean fclean re