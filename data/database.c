#include <stdio.h>
#include "database.h"
#include "sqlite3.h"

sqlite3 *database;

int database_open(void) {

    int result = sqlite3_open("database.db", &database);

    if (result != SQLITE_OK) {
        fprintf(stderr, "database_open() erreur: %s\n", sqlite3_errmsg(database));
        return 0;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS todos (""id INTEGER PRIMARY KEY AUTOINCREMENT,""title TEXT NOT NULL,""done INTEGER NOT NULL DEFAULT 0"");";

    char *error_message = NULL;
    result = sqlite3_exec(database, sql, NULL, NULL, &error_message);

    if (result != SQLITE_OK) {
        fprintf(stderr, "Erreur SQL : %s\n", error_message);
        sqlite3_free(error_message);
        database_close();
        return 0;
    }

    return 1;
}

void database_close(void)
{
    if (database != NULL) {
        sqlite3_close(database);
        database = NULL;
    }
}
