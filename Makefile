SHELL = /bin/sh

B&W = \033[0;0m
RED =  \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m

SRCS = ft_memset.c\
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
SRCDIR = ./sources/

OBJS = $(SRCS:.c=.o)
OBJDIR = ./objects/
OBJ = $(addprefix $(OBJDIR), $(OBJS))

SRCS_B = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_putstr.c\
	ft_strnew.c\
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
SRC_BDIR = ./sources_bonus/

OBJS_B = $(SRCS_B:.c=.o)
OBJ_BDIR = $(OBJDIR)
OBJ_B = $(addprefix $(OBJ_BDIR), $(OBJS_B))

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -ggdb3

ARCHIVE = ar rs
RANLIB = ranlib

HEADER = ./includes/

all: $(NAME)

$(NAME): dir $(OBJ)
	@$(ARCHIVE) $(NAME) $(OBJ)
	@echo "$(GREEN)  MAIN object files archived  $(B&W)"
#	@$(RANLIB) $(NAME)
	@echo "$(GREEN)  Library $(NAME) created  $(B&W)"

bonus: dir $(OBJ) $(OBJ_B)
	@$(ARCHIVE) $(NAME) $(OBJ) $(OBJ_B)
	@echo "$(GREEN)  Main and $(PURPLE)bonus$(B&W) $(GREEN)object files archived  $(B&W)"
#	@$(RANLIB) $(NAME)
	@echo "$(GREEN)  Library $(NAME) with $(PURPLE)BONUS$(B&W) $(GREEN)funtions created  $(B&W)"

dir:
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
#	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)libft.h
#	@test -d $(OBJDIR) || mkdir $(OBJDIR)
#	@mkdir -p $(OBJDIR)
	@$(CC) -I$(HEADER) -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $@ created  $(B&W)"

$(OBJDIR)%.o: $(SRC_BDIR)%.c $(HEADER)libft.h $(HEADER)libft_bonus.h
#	@test -d $(OBJDIR) || mkdir $(OBJDIR)
#	@mkdir -p $(OBJDIR)
	@$(CC) -I$(HEADER) -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $(PURPLE)$@$(B&W) $(GREEN)created  $(B&W)"

so: dir $(OBJ) $(OBJ_B)
	@$(CC) -L ./ -I$(HEADER) $(OBJ) $(OBJ_B) -shared -o libft.so $(FLAGS)
	@echo "$(GREEN)  Library libft.so created  $(B&W)"

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "$(RED)  Object files deleted  $(B&W)"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)  Library $(NAME) deleted  $(B&W)"

re: fclean all

.PHONY: all bonus clean fclean re test so
