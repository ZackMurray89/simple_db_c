#include <assert.h>
#include <stdio.h>
#include "database.h"

int main()
{
    const char *filename = "test2.db";

    // Ensure Clean Start
    remove(filename);

    // Insert Some Records
    assert(db_insert(filename, 1, "Apple"));
    assert(db_insert(filename, 2, "Cherry"));
    assert(db_insert(filename, 3, "Banana"));

    // Scan All Records (Manual Visibility Check)
    printf("Selecting All Records\n");
    int result = db_select_all(filename);
    assert(result);

    printf("test_database Passed\n");

    return 0;
}