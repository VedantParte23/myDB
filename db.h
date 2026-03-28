#ifndef DB_H
#define DB_H
#include <stdbool.h>

typedef struct
{
    int id;
    char name[50];
    char data[200];
} Info;

void create_file(char *file);
void write_file(char *file, Info *data, int total);
void read_file(char *file, Info *data);
void delete_file(char *file);
void update_file(char *file);
void list_files();

#endif
