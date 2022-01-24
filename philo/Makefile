# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 18:32:21 by fbafica           #+#    #+#              #
#    Updated: 2022/01/23 16:56:08 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDES = ./includes/
SOURCE = ./source/main.c \
./source/init/init.c ./source/init/share_data.c \
./source/monitoring/get_dead_philo.c ./source/monitoring/get_full_philo.c \
./source/monitoring/get_priority.c \
./source/routine/routine.c ./source/routine/routine_utils_1.c \
./source/routine/routine_utils_2.c \
./source/utils/ft_atoi.c ./source/utils/ft_atoli.c ./source/utils/ft_isdigit.c \
./source/utils/ft_strcmp.c ./source/utils/ft_calloc.c \
./source/utils/get_tokens_len.c
CC = gcc
FLAGS = -g -Wall -Wextra -Werror -pthread
OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(SOURCE) -I$(INCLUDES) -o $@

%.o: %.c
	@$(CC) -c $< -I$(INCLUDES) -o $@

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

