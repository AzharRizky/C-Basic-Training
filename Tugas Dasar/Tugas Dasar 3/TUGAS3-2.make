CC = gcc
CFLAGS = -Wall

SRCS = TUGAS3-2-main.c TUGAS3-2-functions.c
OBJS = $(SRCS:.c=.o)
EXEC = program.exe

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
