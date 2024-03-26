# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 20:13:13 by tsimitop          #+#    #+#              #
#    Updated: 2024/03/26 18:13:19 by tsimitop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = libft.a
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra

# SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
# ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
# ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
# ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
# ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
# ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
# ft_atoll.c free_split.c

# OBJ_DIR = objects/
# OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# all : $(NAME)

# $(NAME): $(OBJ)
# 	@ar rc $(NAME) $(OBJ)

# $(OBJ_DIR)%.o: %.c
# 	@mkdir -p $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# clean :
# 	@rm -rf $(OBJ_DIR)

# fclean : clean
# 	@rm -f $(NAME)

# re : fclean all

#____________________________
# NAME = libft.a
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# PRINTF_PATH = ft_printf
# OBJ_DIR = objects

# SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
# ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
# ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
# ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
# ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
# ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
# ft_atoll.c free_split.c

# OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

# SRC_PRINT = $(PRINTF_PATH)/ft_printf.c $(PRINTF_PATH)/ft_putstr_fd.c \
# $(PRINTF_PATH)/ft_putnbr_fd.c $(PRINTF_PATH)/ft_putchar_fd.c \
# $(PRINTF_PATH)/ft_puthexlow_fd.c $(PRINTF_PATH)/ft_puthexup_fd.c \
# $(PRINTF_PATH)/ft_putunsign_fd.c $(PRINTF_PATH)/ft_putptr_fd.c

# OBJ_PRINT = $(SRC_PRINT:.c=.o)

# OBJ_PRINT = $(addprefix $(OBJ_DIR_PRINT), $(notdir $(SRC_PRINT:.c=.o)))
# OBJ_DIR_PRINT = $(PRINTF_PATH)/objects/

# all : $(NAME)

# $(NAME): $(OBJ) $(OBJ_PRINT)
# 	@ar rc $(NAME) $(OBJ)

# $(OBJ_DIR)$(PRINTF_PATH)/%.o: $(PRINTF_PATH)/%.c
# 	# @mkdir -p $(OBJ)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR_PRINT)%.o: %.c
# 	# @mkdir -p $(OBJ)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# clean :
# 	@rm -rf $(OBJ) $(OBJ_PRINT)

# fclean : clean
# 	@rm -f $(NAME)

# re : fclean all

#_______________________________________
# NAME = libft.a
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# PRINTF_PATH = ft_printf
# OBJ_DIR = objects

# SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
# ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
# ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
# ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
# ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
# ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
# ft_atoll.c free_split.c

# SRC_PRINT = $(addprefix $(PRINTF_PATH)/, \
# ft_printf.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c \
# ft_puthexlow_fd.c ft_puthexup_fd.c ft_putunsign_fd.c ft_putptr_fd.c)

# OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# OBJ_PRINT = $(addprefix $(OBJ_DIR)/, $(SRC_PRINT:.c=.o))

# all: $(NAME)

# $(NAME): $(OBJ_DIR) $(OBJ) $(OBJ_PRINT)
# 	@ar rc $(NAME) $(NAME) $(OBJ) $(OBJ_PRINT)

# $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR):
# 	@mkdir -p $@

# clean:
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all

#________________________________________

# NAME = libft.a
# CC = gcc
# CFLAGS = -Wall -Werror -Wextra
# PRINTF_PATH = ft_printf
# OBJ_DIR = $(PRINTF_PATH)/objects

# SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
# ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
# ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
# ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
# ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
# ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
# ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
# ft_atoll.c free_split.c

# SRC_PRINT = $(addprefix $(PRINTF_PATH)/, \
# ft_printf.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c \
# ft_puthexlow_fd.c ft_puthexup_fd.c ft_putunsign_fd.c ft_putptr_fd.c)

# OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# OBJ_PRINT = $(addprefix $(OBJ_DIR)/, $(SRC_PRINT:.c=.o))

# all: $(NAME)

# $(NAME): $(OBJ_DIR) $(OBJ) $(OBJ_PRINT)
# 	@ar rc $(NAME) $(OBJ) $(OBJ_PRINT)

# $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR):
# 	@mkdir -p $@

# clean:
# 	@rm -rf $(OBJ_DIR)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all
#________________________________________________

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PRINTF_PATH = ft_printf/

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_atoll.c free_split.c

SRC_PRINTF = $(PRINTF_PATH)/ft_printf.c $(PRINTF_PATH)/ft_putstr_fd.c \
$(PRINTF_PATH)/ft_putnbr_fd.c $(PRINTF_PATH)/ft_putchar_fd.c \
$(PRINTF_PATH)/ft_puthexlow_fd.c $(PRINTF_PATH)/ft_puthexup_fd.c \
$(PRINTF_PATH)/ft_putunsign_fd.c $(PRINTF_PATH)/ft_putptr_fd.c

OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_PRINTF = $(addprefix $(OBJ_DIR), $(notdir $(SRC_PRINTF:.c=.o)))

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ) $(OBJ_PRINTF)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF_PATH)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all