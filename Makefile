# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabarros <mabarros@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 19:12:30 by mabarros          #+#    #+#              #
#    Updated: 2025/07/06 04:33:11 by mabarros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(lib_dir) -I$(lib_dir)/ft_printf -I$(lib_dir)/get_next_line

prog_name = push_swap
name = libpushswap.a

push_functions = push_swap.c push_swap_utils.c make_stack.c \
				push_swap_more_utils.c commands.c more_commands.c \

push_objs = $(push_functions:.c=.o)

lib_dir = Libft
libft_lib = $(lib_dir)/libft.a

link = -L$(lib_dir) -lft

all: $(name)

$(name): $(push_objs) 
	@$(MAKE) -C $(lib_dir)
	@$(CC) $(CFLAGS) $(push_objs) $(link) -o $(prog_name)
	@echo "\n\n\n\n|------------------------------------------------PUSH_SWAP_CREATED----------------------------------------------------------|"
	
clean:
	@rm -rf $(push_objs)
	@$(MAKE) -C $(lib_dir) clean
	@echo "\n\n\n\n|------------------------------------------------PUSH_SWAP_DELETED----------------------------------------------------------|"
	
fclean: clean
	@rm -rf $(name)
	@rm -rf $(prog_name)
	@$(MAKE) -C $(lib_dir) fclean
	@echo "\n\n\n\n|---------------------------------------------PUSH_SWAP_FULLY_DELETED----------------------------------------------------------|"

re : fclean all
