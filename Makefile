CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

# Main DB Program
mydb: $(OBJ)
	$(CC) $(CFLAGS) -o build/mydb $(OBJ)

# Storage Test
test_storage: src/storage.c tests/test_storage.c
	$(CC) $(CFLAGS) -o build/test_storage src/storage.c tests/test_storage.c
	./build/test_storage

# Database Test
test_database: src/database.c src/storage.c tests/test_database.c
	$(CC) $(CFLAGS) -o build/test_database src/database.c src/storage.c tests/test_database.c
	./build/test_database

# Run All Tests
test: test_storage test_database

clean:
	rm -f src/*.o build/mydb