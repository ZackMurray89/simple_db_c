#include <stdio.h>
#include <string.h>
#include "database.h"

int db_insert(const char *filename, int key, const char *value)
{
    FILE *f = fopen(filename, "a+b"); // Append+Read, Binary Mode
    if (!f)
    {
        perror("fopen");
        return 0;
    }

    Record r;
    r.key = key;
    strncpy(r.value, value, sizeof(r.value) - 1);
    r.value[sizeof(r.value) - 1] = '\0'; // Enusres Null-Termination

    write_record(f, &r);
    fclose(f);
    return 1; // Success
}

int db_select_all(const char *filename)
{
    FILE *f = fopen(filename, "rb"); // Read-Only, Binary
    if (!f)
    {
        perror("fopen");
        return 0;
    }

    Record r;
    while (read_record(f, &r))
    {
        printf("%d | %s\n", r.key, r.value);
    }

    fclose(f);
    return 1; // Success
}