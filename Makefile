# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srachdi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 15:21:04 by srachdi           #+#    #+#              #
#    Updated: 2023/01/03 20:00:50 by srachdi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
MLX_FLAGS = -lmlx -framework openGL -framework appkit
INCLUDES = ./so_long.h
INCLUDES_BONUS = ./so_long_bonus.h

SRCS = so_long.c get_next_line.c get_next_line_utils.c map.c validpath.c key.c image.c utils.c utils2.c
OBJS = $(SRCS:.c=.o)
SRCS_BONUS = so_long_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c map_bonus.c validpath_bonus.c key_bonus.c image_bonus.c utils_bonus.c utils2_bonus.c utils3_bonus.c loadsprites_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o : %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
	@echo "\033[0;31m So long ,and thanks for all the fish.\033[0m"
bonus	: $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS)
clean	:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "\033[0;31m Cleaned.\033[0m"
fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "\033[0;31m Cleaned all. \033[0m"
re : fclean all
	@echo "\033[0;31m Cleaned.\033[0m"
	@echo "\033[0;31m making all.\033[0m"
.PHONY : all clean fclean re bonus
