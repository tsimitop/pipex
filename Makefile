################################################################################
#									CONSTANTS								   #
################################################################################
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = libft.h pipex.h
LIBFT_PATH = ./Libft
LIBFT := $(LIBFT_PATH)/libft.a
LDFLAGS = -L $(LIBFT_PATH) -lft

NAME = pipex

################################################################################
#									MAIN PART								   #
################################################################################

SRC =	main.c\
		path.c\
		processes.c\
		errors_close.c

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(OBJ) : %.o : %.c
	@$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $< -o $@

clean :
	@echo "Removing $(OBJ)"
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re : fclean all

################################################################################
#									LIBFT									   #
################################################################################

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_PATH) --no-print-directory

.PHONY :
	all clean fclean re
