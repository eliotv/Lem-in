# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 15:11:12 by evanheum          #+#    #+#              #
#    Updated: 2017/11/16 19:59:43 by evanheum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -I includes -I libft/includes
LDFLAGS += -L libft/ -lft

LIBFT := libft/libft.a

LEMINDR = \
	lemin.c \
	read.c \
	init.c \
	store.c \

SRC = $(addprefix src/, $(LEMINDR))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): %.o: %.c
	@$(CC) -c $(LDFALGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o  $@ $^
	@echo "\033[32m    ~*COMPILED LEM-IN*~\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[31m~*LEM-IN OBJECT FILES REMOVED*~\033[0m"

fclean:
	@rm -rf $(OBJ) $(NAME)
	@make -C libft fclean
	@echo "\033[31m~*LEM-IN EXECUTABLE REMOVED*~\033[0m"

re: fclean all