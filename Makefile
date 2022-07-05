# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: chartema <chartema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/28 11:50:23 by chartema      #+#    #+#                  #
#    Updated: 2022/06/29 10:49:53 by chartema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -f

LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42
INC_PATH = ./lib/MLX42/include/ ./lib/libft/ ./include

FILES = main.c
OBJS = $(FILES:.c=.o)
INC = $(addprefix -I, $(INC_PATH)) 

MLX_FLAGS = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(LIBMLX)
	$(CC) $(MLX_FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $<

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(LIBMLX) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re

