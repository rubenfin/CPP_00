CC = c++
CFLAGS = -Wall -Wextra -Werror -g
SRCS = $(wildcard *.cpp) 
OBJS = $(patsubst %.cpp,obj/%.o,$(SRCS))

TARGET = Account

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

obj/%.o: %.cpp | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

clean:
	$(RM) -r obj/ $(TARGET)
