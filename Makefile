# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 18:32:21 by fbafica           #+#    #+#              #
#    Updated: 2022/01/26 00:25:46 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDES = ./includes/
SOURCE = main.c init.c share_data.c get_dead_philo.c get_full_philo.c \
get_priority.c routine.c routine_utils_1.c routine_utils_2.c \
ft_atoi.c ft_atoli.c ft_isdigit.c ft_strcmp.c ft_calloc.c get_tokens_len.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -pthread
OBJECTS = $(SOURCE:%.c=$(OBJECTS_DIR)%.o)
OBJECTS_DIR = ./objects/
VPATH = ./source/ ./source/init/ ./source/monitoring/ ./source/routine/ ./source/utils/


all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) -I$(INCLUDES) -o $@

$(OBJECTS_DIR)%.o: %.c
	@$(CC) $(FLAGS) -c $< -I$(INCLUDES) -o $@

$(OBJECTS_DIR):
	@mkdir -p objects

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(OBJECTS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

