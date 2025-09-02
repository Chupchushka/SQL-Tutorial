#include <stdio.h>
#include <sqlite3.h>

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

void create_table(sqlite3* database){
    char* errMsg;
    char* sql = "CREATE TABLE STUDENT(" 
                "ID INT PRIMARY KEY NOT NULL,"
                "FIRST_NAME TEXT NOT NULL,"
                "LAST_NAME TEXT NOT NULL,"
                "EMAIL TEXT NOT NULL)";

    int rc = sqlite3_exec(database, sql, NULL, 0, &errMsg);
    if(rc != SQLITE_OK){
        printf("Error in executing SQL: %s \n", errMsg);
        //free the error message
        sqlite3_free(errMsg);
    } else {
        printf("table STUDENT made successfully");
        
    }                
}


int main(){
    
    const char* filename = "db.sqlite3";
    open_db(filename, db); 
    create_table(db);
    sqlite3_close(db);

    return 0;
}