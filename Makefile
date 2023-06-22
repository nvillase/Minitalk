NAME = client
NAME2 = server
CC = gcc
CCFLAG = -g -Wall -Wextra -Werror
LIB = ./include/libft/libft.a
RM = rm -f
SRCS = client.c
OBJS = $(SRCS:.c=.o)
SRCS2 = server.c
OBJS2 = $(SRCS2:.c=.o)
CMD = -L ./include/libft/ -lft

all: $(LIB) $(NAME) $(NAME2)

$(LIB):
	make -C ./include/libft/ all

.c.o:
	$(CC) $(CCFLAG) $(CMD) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CCFLAG) $(OBJS) $(CMD) -o $(NAME)

$(NAME2): $(OBJS2) $(LIB)
	$(CC) $(CCFLAG) $(OBJS2) $(CMD) -o $(NAME2)

clean:
	$(RM) $(OBJS) $(OBJS2)
	make -C ./include/libft/ clean

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all