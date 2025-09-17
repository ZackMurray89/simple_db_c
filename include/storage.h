#ifndef STORAGE_H
#define STORAGE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
    char value[256];
} Record;

void write_record(FILE *f, Record *r);
int read_record(FILE *f, Record *r);

#endif