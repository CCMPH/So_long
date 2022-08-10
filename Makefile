# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: chartema <chartema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/28 11:50:23 by chartema      #+#    #+#                  #
#    Updated: 2022/08/10 09:13:56 by chartema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g
CC = gcc
RM = rm -rf

HEADERFILES = includes/so_long.h
MLX_FLAGS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a $(LIBGNL)/get_next_line.a

FILES = main.c check_map.c utils.c validation.c\
		init_mlx.c set_mlx.c init_movement.c set_movement.c exit.c
OBJ_FILES = $(FILES:.c=.o)
OBJS = $(addprefix obj/, $(OBJ_FILES))

LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42
LIBGNL = ./lib/GNL
INC_PATH = ./lib/MLX42/include/ ./lib/libft/ ./lib/GNL/ ./include
INC = $(addprefix -I, $(INC_PATH)) 

all: $(NAME)

$(NAME): $(OBJS) $(HEADERFILES)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBMLX)
	@$(MAKE) -C $(LIBGNL)
	$(CC) $(MLX_FLAGS) $(OBJS) -o $(NAME) 
#-g -fsanitize=address

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

norm:
	norminette lib/GNL/ lib/libft/ includes/ src/

clean:
	$(RM) ./obj
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBGNL) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBGNL) fclean

re: clean all

.PHONY: all, clean, fclean, re

