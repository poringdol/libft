BW = \033[0;0m
RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m
SRC = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

SRCBON = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_putstr.c\
	ft_strnew.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_striter.c\
	ft_strequ.c\
	ft_strclr.c\
	ft_putchar.c\
	ft_putendl.c\
	ft_strnequ.c\
	ft_striteri.c\
	ft_strdel.c\
	ft_strmap.c\
	ft_putnbr.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strstr.c\
	ft_strcmp.c\
	ft_lstmap.c\
	ft_islower.c\
	ft_isupper.c\
	ft_isblank.c\
	ft_iscntrl.c\
	ft_isgraph.c\
	ft_isspace.c\
	ft_isxdigit.c\
	ft_strcasecmp.c\
	ft_strncasecmp.c\
	ft_strcasestr.c\
	ft_strupcase.c\
	ft_strlowcase.c
OBJBON = $(SRCBON:.c=.o)

NAME = libft.a

CC = gcc

HEADER = -I./

FLAGS = -Wall -Werror -Wextra -fPIC -ggdb3

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)  Mandatory object files archived  $(BW)"
	@ranlib $(NAME)
	@echo "$(GREEN)  Library $(NAME) created  $(BW)"
	
bonus: $(OBJ)
	ar rc $(NAME) $(OBJ) $(OBJBON)
	@echo "$(GREEN)  Mandatory and bonus object files archived  $(BW)"
	@ranlib $(NAME)
	@echo "$(GREEN)  Library $(NAME) with $(PURPLE)BONUS$(BW) $(GREEN)funtions created  $(BW)"

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -c $(SRC)
	$(CC) $(FLAGS) $(HEADER) -c $(SRCBON)
	@echo "$(GREEN)  Object files created  $(BW)"

so:
	$(CC) -L ./ $(FLAGS) $(OBJ) $(OBJBON) -shared -o libft.so

clean:
	@/bin/rm -f $(OBJ) $(OBJBON)
	@echo "$(RED)  Object files deleted  $(BW)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)  Library $(NAME) deleted  $(BW)"

re: fclean all

.PHONY: all clean fclean re test
