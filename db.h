#ifndef DB_H
#define DB_H
#include <stdbool.h>

typedef struct 
{
    char name[50];
    int id;
    char data[200];
}Info;



void create_file(char *file);
bool write_file(char *filename , Info *data, int total);
void read_file(char *file);
void delete_file(char *file);
void update_file(char *file);
void list_files();

#endif 
