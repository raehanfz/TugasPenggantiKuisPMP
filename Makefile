CFLAGS = -Iinclude -Wall -Wextra -g
SRCS = main.c source/Library.c
OBJ = $(SRCS:.c=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	gcc $(OBJ) -o $@

main.o: main.c
	gcc $(CFLAGS) -c $< -o $@

source/%.o: source/%.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run