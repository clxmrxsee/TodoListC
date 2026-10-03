#include <stdio.h>
#include "database.h"
#include "sqlite3.h"

int database_open(void) {
    sqlite3 *database;

    int result = sqlite3_open("database.db", &database);

    if (result != SQLITE_OK) {
        fprintf(stderr, "database_open() erreur: %s\n", sqlite3_errmsg(database));
        return 0;
    }

    return 1;
}
