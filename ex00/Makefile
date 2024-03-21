CC = c++
CFLAGS = -Wall -Wextra -Werror

TARGET = megaphone

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	@$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp
	@echo "$(GREEN)Compiled megaphone!$(DEFAULT)"

clean:
	@$(RM) $(TARGET)
	@echo "$(RED)Removed megaphone!$(DEFAULT)"

fclean: clean

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m