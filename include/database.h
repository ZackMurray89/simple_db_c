#ifndef DATABASE_H
#define DATABASE_H

#include "storage.h"

// Insert Record Into Database (Appends To File)
int db_insert(const char *filename, int key, const char *value);

// Read and Print All Records From The Database
int db_select_all(const char *filename);

// Read and Print Record(s) Matching A Key
int db_select_key(const char *filename, int key);

#endif