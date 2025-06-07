# Nama executable
TARGET = perbandingan

# Compiler dan flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SRCS = header_adiva.c perbandingan.c
OBJS = $(SRCS:.c=.o)

# Rule utama
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule kompilasi .c ke .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Bersih-bersih
clean:
	rm -f $(OBJS) $(TARGET)
