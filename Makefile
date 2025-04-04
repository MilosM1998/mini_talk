CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SERVER_SRC = ./server.c
CLIENT_SRC = ./client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

SERVER = server
CLIENT = client

RM = rm -f

all: $(SERVER) $(CLIENT) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
fclean: clean 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(CLIENT) $(SERVER)
re:	fclean all

.PHONY: all clean fclean re