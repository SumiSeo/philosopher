NAME = philo

#SRCS AND OBJS FOR COMPILING
SRCS = philo.c error_handler.c \
		parsing/parsing_utils.c
OBJS = $(SRCS:%.c=%.o)

#FLAGS
CC = clang
CFLAGS = -Wall -Werror -Wextra -pthread
DEBUGGER = -g3

all : $(NAME)
%.o : %.CC
			$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(DEBUGGER)
clean :
			rm -rf $(OBJS)
fclean :
			rm -rf $(NAME)
re : fclean all