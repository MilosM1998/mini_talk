# Kompajler i flagovi
CC = cc
CFLAGS = -Wall -Wextra -Werror  -I. -I./libft 
# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Izvori
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Objekti
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Izvršni fajlovi
SERVER = server
CLIENT = client

# Brisanje fajlova
RM = rm -f

# Podrazumevana meta
all: $(LIBFT) $(SERVER) $(CLIENT)

# Pravi server
$(SERVER): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

# Pravi klijenta
$(CLIENT): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

# Pravljenje object fajlova
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pravi libft ako nije kompajliran
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Čišćenje object fajlova
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

# Čišćenje izvršnih i object fajlova
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(SERVER) $(CLIENT)

# Rekompilacija
re: fclean all

# Ignorisanje lažnih meta
.PHONY: all clean fclean re
