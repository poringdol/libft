NAME=libft.a
SRC=ft_memset.c\
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
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
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
OBJ = $(SRC:.c=.o)
HEADER=-I./
FLAGS=-Wall -Werror -Wextra -ggdb3

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -fPIC $(HEADER) -c $? $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

so:
	gcc $(FLAGS) $(OBJ) -shared -o libft.so

test: $(SRC)
	@gcc $(FLAGS) $(SRC) test.c $(HEADER) -o test

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
