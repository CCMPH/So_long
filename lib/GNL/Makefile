NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = get_next_line_utils.c get_next_line.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o:%.c get_next_line.h
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=20 -c $<

clean:
	@$(RM) $(OBJS)

normi: $(FILES)
	norminette $(FILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, normi, normib