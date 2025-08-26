# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 16:27:41 by myli-pen          #+#    #+#              #
#    Updated: 2025/08/27 00:53:16 by myli-pen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=push_swap

LIBFT		=$(DIR_LIBFT)libft.a

CC			=cc
CFLAGS		=-Wall -Wextra -Werror -Wunreachable-code -O3
MAKEFLAGS	+= --no-print-directory

DIR_LIBFT	=$(DIR_LIB)libft/
DIR_INC		=inc/
DIR_SRC		=src/
DIR_OBJ		=obj/
DIR_LIB		=lib/
DIR_DEP		=dep/

INCS		=$(addprefix -I , \
				$(DIR_INC) $(DIR_LIBFT)$(DIR_INC))
SRCS		=$(addprefix $(DIR_SRC), \
				main.c parsing.c operations.c sorting.c indexing.c)
OBJS		=$(patsubst $(DIR_SRC)%.c, $(DIR_OBJ)%.o, $(SRCS))
DEPS		=$(patsubst $(DIR_SRC)%.c, $(DIR_DEP)%.d, $(SRCS))

BLUE		=\033[1;34m
YELLOW		=\033[1;33m
GREEN		=\033[1;32m
RED			=\033[1;31m
COLOR		=\033[0m

all: $(LIBFT) $(NAME)

$(DIR_OBJ):
	@mkdir -p $(DIR_LIB) $(DIR_OBJ) $(DIR_DEP)
	@echo "$(GREEN) [+]$(COLOR) created missing directories"

$(LIBFT):
	@echo "$(GREEN) [+]$(COLOR) compiling libft.a"
	@make -C $(DIR_LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(YELLOW) [✔] $(NAME) created$(COLOR)"

$(DIR_OBJ)%.o: $(DIR_SRC)%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP -MF $(patsubst $(DIR_OBJ)%.o, $(DIR_DEP)%.d, $@) $(INCS)
	@echo "$(GREEN) [+]$(COLOR) compiling $@"

clean:
	@if [ -d "$(DIR_OBJ)" ]; then \
		rm -rf $(DIR_OBJ) $(DIR_DEP); \
		echo "$(RED) [-]$(COLOR) removed $(DIR_OBJ)"; \
		echo "$(RED) [-]$(COLOR) removed $(DIR_DEP)"; \
	fi
	@make -C $(DIR_LIBFT) clean

fclean: clean
	@make -C $(DIR_LIBFT) fclean
	@if [ -e "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(RED) [-]$(COLOR) removed $(NAME)"; \
	fi

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(DEPS)

-include $(DEPS)
