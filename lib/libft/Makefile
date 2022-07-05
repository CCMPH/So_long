NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_atoi.c ft_bzero.c ft_calloc.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strchr.c ft_strdup.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_tolower.c ft_toupper.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJS = $(FILES:.c=.o)
BONUS_OBJS = $(BONUS_FILES:.c=.o)

ifdef BONUS
RELEVANT_OBJS = $(OBJS) $(BONUS_OBJS)
else
RELEVANT_OBJS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(RELEVANT_OBJS)
	@$(AR) $(NAME) $(RELEVANT_OBJS)
	@echo "Create archive file $@"

%.o:%.c libft.h
	@$(CC) $(CFLAGS) -c $<
	@echo "Compiling $@"

bonus: 
	@$(MAKE) BONUS=1

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "Removing object files"

normi: $(FILES)
	norminette $(FILES)

normib:	$(BONUS_FILES)
	norminette $(BONUS_FILES)

fclean: clean
	@$(RM) $(NAME)
	@echo "Removing archive file"

re: fclean all

.PHONY: all, clean, fclean, re, normi, normib
