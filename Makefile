CC = gcc
CFLAGS = -O2 -Wall -Wextra

# Targets
all: good bad

# Link main.c with good_strlen.c
good: main.o good_strlen.o
	$(CC) $(CFLAGS) -o good main.o good_strlen.o

# Link main.c with bad_strlen.c
bad: main.o bad_strlen.o
	$(CC) $(CFLAGS) -o bad main.o bad_strlen.o

# Compile object files
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

good_strlen.o: good_strlen.c
	$(CC) $(CFLAGS) -c good_strlen.c

bad_strlen.o: bad_strlen.c
	$(CC) $(CFLAGS) -c bad_strlen.c

# Clean up
clean:
	rm -f *.o good bad
