# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlopez <carlopez@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 12:23:06 by carlopez          #+#    #+#              #
#    Updated: 2025/02/03 17:32:18 by carlopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

AR = ar
ARFLAGS = rcs

LIB = lib/push_swap.h
PRINTFDIR = printf
PRINTF = printf/libftprintf.a
MAIN = main/main.c 

#COLOURS AND TEXT FORMAT
LIGHT_YELLOW	= \033[1;33m
BOLD_GREEN    = \033[1;32m
BOLD_PURPLE   = \033[1;35m
BOLD_CYAN     = \033[1;36m
PINK_LIGHT= \033[38;5;217m
RED_BRIGHT     = \033[38;2;255;0;0m
PINK_FUCHSIA    = \033[38;2;255;20;147m

RESET  = \033[0m

SRC = src/find_utils.c src/check_utils.c src/utils_special_sort.c src/find_utils_extra.c src/sort_utils_extra.c src/sort_utils_extra2.c src/assign_chunks_utils.c src/assign_chunks.c src/special_sort.c src/sort.c src/sort_utils.c
BONUS_SRC = bonus/check.c bonus/Get_next_line/get_next_line.c bonus/Get_next_line/get_next_line_utils.c
SHARED_SRC = src/utils_build_stack.c src/build_stack.c src/push.c src/swap.c src/rotate.c src/reverse_rotate.c src/utils_push_swap.c

ifndef BONUS
	OBJ = $(SRC:.c=.o) $(SHARED_SRC:.c=.o)
else
	OBJ = $(BONUS_SRC:.c=.o) $(SHARED_SRC:.c=.o)
	MAIN = bonus/main.c
	NAME = checker
endif

all: 
	@echo "$(PINK_FUCHSIA)\n MAKING PUSH_SWAP\n$(RESET)"
	@$(MAKE) --no-print-directory $(NAME)

$(NAME): $(MAIN) $(OBJ) $(PRINTF)
	@echo "$(BOLD_CYAN)\nCompiling program...$(RESET)"
	$(CC) $(CCFLAGS) $(MAIN) $(OBJ) $(PRINTF) -o $(NAME)
	@echo "$(BOLD_CYAN)\n!Compilation completed, $(LIGHT_YELLOW)push_swap🚀$(BOLD_CYAN) ready to be used!\n$(RESET)"

$(PRINTF):
	@echo "$(BOLD_PURPLE)\nCompiling printf...$(RESET)"
	@$(MAKE) --silent -C $(PRINTFDIR)

%.o: %.c $(LIB) Makefile
	@echo "$(PINK_LIGHT)🡲 Creating object...$(RESET)"
	$(CC) $(CCFLAGS) -c $< -o $@

bonus:
	@make BONUS=1 --no-print-directory

clean:
	@echo "$(RED_BRIGHT)\nThrowing object files of Push_swap to 🗑️$(RESET)"
	rm -f $(OBJ)
	@echo "$(RED_BRIGHT)\nThrowing object files of Printf to 🗑️$(RESET)"
	rm -f $(PRINTFDIR)/*.o

fclean: clean
	@echo "$(RED_BRIGHT)\nDestroying printf 💥$(RESET)"
	rm -f $(PRINTF)
	@echo "$(RED_BRIGHT)\nDestroying program 💥$(RESET)"
	rm -f $(NAME)
	@echo "\n$(BOLD_GREEN) Bye bye 👋 $(RESET)\n" 

re: fclean all

.PHONY: all clean fclean re bonus
