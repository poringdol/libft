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
SRCDIR = ./

OBJS = $(SRCS:.c=.o)
OBJDIR = ./
OBJ = $(addprefix $(OBJDIR), $(OBJS))

SRCS_B = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_putstr_bonus.c\
	ft_strnew_bonus.c\
	ft_memdel_bonus.c\
	ft_striter_bonus.c\
	ft_strequ_bonus.c\
	ft_strclr_bonus.c\
	ft_putchar_bonus.c\
	ft_putendl_bonus.c\
	ft_strnequ_bonus.c\
	ft_striteri_bonus.c\
	ft_strdel_bonus.c\
	ft_strmap_bonus.c\
	ft_putnbr_bonus.c\
	ft_strcpy_bonus.c\
	ft_strncpy_bonus.c\
	ft_strcat_bonus.c\
	ft_strncat_bonus.c\
	ft_strstr_bonus.c\
	ft_strcmp_bonus.c\
	ft_islower_bonus.c\
	ft_isupper_bonus.c\
	ft_isblank_bonus.c\
	ft_iscntrl_bonus.c\
	ft_isgraph_bonus.c\
	ft_isspace_bonus.c\
	ft_isxdigit_bonus.c\
	ft_strcasecmp_bonus.c\
	ft_strncasecmp_bonus.c\
	ft_strcasestr_bonus.c\
	ft_strupcase_bonus.c\
	ft_strlowcase_bonus.c
SRC_BDIR = ./

OBJS_B = $(SRCS_B:.c=.o)
OBJ_BDIR = $(OBJDIR)
OBJ_B = $(addprefix $(OBJ_BDIR), $(OBJS_B))

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -ggdb3

ARCHIVE = ar rs
RANLIB = ranlib

HEADER = ./

all: $(NAME)

$(NAME): $(OBJ)
	@$(ARCHIVE) $(NAME) $(OBJ)
	@echo "$(GREEN)  MAIN object files archived  $(B&W)"
	@echo "$(GREEN)  Library $(NAME) created  $(B&W)"

bonus: $(OBJ) $(OBJ_B)
	@$(ARCHIVE) $(NAME) $(OBJ) $(OBJ_B)
	@echo "$(GREEN)  Main and $(PURPLE)bonus$(B&W) $(GREEN)object files archived  $(B&W)"
	@echo "$(GREEN)  Library $(NAME) with $(PURPLE)BONUS$(B&W) $(GREEN)funtions created  $(B&W)"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)libft.h
	@$(CC) -I$(HEADER) -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $@ created  $(B&W)"

$(OBJDIR)%.o: $(SRC_BDIR)%.c $(HEADER)libft.h
	@$(CC) -I$(HEADER) -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $(PURPLE)$@$(B&W) $(GREEN)created  $(B&W)"

clean:
	@/bin/rm -rf $(OBJDIR)*.o
	@echo "$(RED)  Object files deleted  $(B&W)"

#so:
#	@$(CC) -L ./ -I$(HEADER) $(OBJ) $(OBJ_B) -shared -o libft.so $(FLAGS)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)  Library $(NAME) deleted  $(B&W)"

re: fclean all

.PHONY: all bonus clean fclean re
