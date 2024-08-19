NAME = philo

# SRCS AND OBJS FOR COMPILING
SRCS = philo.c error_handler/error_print.c utils/parsing_utils.c \

OBJ_DIR = obj 

# OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
OBJS = $(SRCS:%.c=%.o)


#FLAGS
CC = clang
CFLAGS = -pthread -Wall -Werror -Wextra 
DEBUGGER = -g3

all : $(NAME)
# $(OBJ_DIR)/%.o : %.c
# 				mkdir -p $(dir $@)
# 				$(CC) $(CFLAGS) $(DEBUGGER) -c $< -o $@
%.o : %.c 
		$(CC) $(CFLAGS) -c $< -o $@ #(DEBUGGER)

$(NAME) : $(OBJS)
			$(CC) $(OBJS) -o $(NAME) 
clean : 
			rm -rf $(OBJ_DIR)

fclean : clean	
			rm -rf $(NAME)

re : fclean all
