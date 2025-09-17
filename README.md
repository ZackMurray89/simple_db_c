# MyDB (Toy Database in C)

myDB is a simple database project written to help me learn the C Programming Language.
The goal is to learn how databases work internally by building the core pieces (step by step) --
starting with file storage, then adding indexing, quieres, and eventually transactions.

## Current Status

- Implemented:
  - **Record Definition**: (`Record` with `key` and `value`)
  - **Stroage Layer**
    - `write_record(FILE *f, Record *r)` -> appends a reocrd to a file
    - `read_record(FILE *f, Record *r)` -> reads back a record from a file

- Tests:
  - `tests/test_storage.c`:
    - Writes a record to the `test.db`
    - Reads it back
    - Asserts the values are the same

- In Progress:
  - Add CLI commands to interact with the database (`insert`, `select`)
  - Organize records into fixed-size pages
  - Build a tiny SQL-like parser
  - Explore durability (logging, crash-recovery)

## Project Structure


	

mydb/
├── src/
│   ├── main.c        # Program entry point
│   ├── storage.c     # Handles reading/writing records
├── include/
│   └── storage.h     # Record definition + storage function declarations
├── tests/
│   └── test_storage.c # Test for storage layer
├── build/            # Compiled binaries
├── Makefile          # Build system
└── README.md         # This file