CC = cc 
CFLAGS = -Wall -Wextra -Werror 

SERVER_SRC = ./server.c
CLIENT_SRC = ./client.c ./client_utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

SERVER = server
CLIENT = client

RM = rm -f

GREEN	= \e[0;32m
RED		= \e[0;31m
YELLOW	= \e[0;33m
BLUE	= \e[0;34m
RESET	= \e[0m


all: $(SERVER) $(CLIENT) $(LIBFT)

$(LIBFT):
	@echo "$(BLUE)Making libft.. $(MAKE) -C $(LIBFT_DIR)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) && echo "$(GREEN)Libft successfully compiled!$(RESET)"


$(SERVER): $(SERVER_OBJ) $(LIBFT)
	@echo "$(BLUE)Compiling server..$(RESET)"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER) && echo "$(GREEN)Server successfully compiled.$(RESET)"

$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	@echo "$(BLUE)Compiling client..$(RESET)"
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT) && echo "$(GREEN)Client successfully compiled.$(RESET)"

%.o: %.c
	@echo "$(YELLOW)$(CC) $(CFLAGS) -c $< -o $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "$(YELLOW) Cleaning objects..$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
fclean: clean 
	@echo "$(YELLOW) Cleaning..$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(CLIENT) $(SERVER)
re:	fclean all

.PHONY: all clean fclean re