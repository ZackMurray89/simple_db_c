#include "storage.h"
#include <stdio.h>

void write_record(FILE *f, Record *r)
{
    fwrite(r, sizeof(Record), 1, f);
}

int read_record(FILE *f, Record *r)
{
    return fread(r, sizeof(Record), 1, f);
}