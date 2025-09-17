#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "storage.h"

int main()
{
    // Create & Open A Test File
    FILE *f = fopen("test.db", "w+b");
    if (!f)
    {
        perror("fopen");
        return 1;
    }

    // Write Record
    Record r1 = {1, "Apple"};
    Record r2 = {2, "Cherry"};
    Record r3 = {3, "Banana"};

    write_record(f, &r1);
    write_record(f, &r2);
    write_record(f, &r3);

    // Reset To Beginning Of File
    rewind(f);

    // Read Record Back
    Record out;
    int count = 0;
    while (read_record(f, &out))
    {
        printf("Read Record: key=%d, value=%s\n", out.key, out.value);
        count++;
    }

    fclose(f);

    // Print Test Output To Know If It Passed
    assert(count == 3);
    printf("test_storage Passed\n");

    return 0;
}