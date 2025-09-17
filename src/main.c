#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

#define DB_FILE "mydb.db"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Useage:\n");
		printf("	%s insert <key> <value>\n", argv[0]);
		printf("	%s select\n", argv[0]);
		printf("	%s select <key>", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "insert") == 0) {
		if (argc < 4) {
			fprintf(stderr, "Error: Insert Requires <key> <value>\n");
			return 1;
		}

		int key = atoi(argv[2]);
		const char *value = argv[3];

		if (!db_insert(DB_FILE, key, value)) {
			fprintf(stderr, "Insert Failed\n");
			return 1;
		}

		printf("Inserted (%d, %s)\n", key, value);
	} else if (strcmp(argv[1], "select") == 0) {
		if (argc == 2) {
			if (!db_select_all(DB_FILE)) {
				fprintf(stderr, "Select All Failed\n");
				return 1;
			}
		} else if (argc == 3) {
			int key = atoi(argv[2]);
			if (!db_select_key(DB_FILE, key)) {
				printf("No Record Found With Key=%d\n", key);
			}
		} else {
			fprintf(stderr, "Error: Select Usege %s Select [key]\n", argv[0]);
			return 1;
		}
	} else {
		fprintf(stderr, "Unknown Command: %s\n", argv[1]);
	}

	return 0;