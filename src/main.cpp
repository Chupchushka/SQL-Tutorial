#include <stdio.h>
#include <sqlite3.h>
#include <string>

sqlite3 *db;

void open_db(const char* filename, sqlite3* database){
    int opened = sqlite3_open(filename, &database);
    if(opened){
        printf("Can't open database: %s\n", sqlite3_errmsg(database));
    } else {
        printf("Opened database successfully\n");
        db = database;
    }
}

int main(){
    const char* filename = "db.sqlite3";
    open_db(filename, db); 

    return 0;
}