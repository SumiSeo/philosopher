NAME = philo

#SRCS AND OBJS FOR COMPILING
SRCS = philo.c

#INCLUDES = libftmake

OBJS = $(SRCS:%.c=%.o)

#FLAGS
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pthread
# CLIB = -L libft/ -l libft
DEBUGGER = -g3

all : $(NAME)
%.o : %.CC
			$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(CLIB) $(DEBUGGER)
clean :
			rm -rf $(OBJS)
fclean :
			rm -rf $(NAME)
re : fclean all