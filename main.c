#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "db.h"


struct student
{
    char name[30];
    int id;
    char info[100];
};



int main()
{
    char input[100];

    while (1)
    {
        printf("myDB> ");
        fgets(input, 100, stdin);

        char* command = strtok(input, " \n");
        char *argument = strtok(NULL, " \n");

        if (command == NULL)
        {
            continue;
        }

        if (argument == NULL)
        {
            if (strcmp(command, "exit") == 0)
           {
               printf("\nExited succesfully");
               return 0;
           }
    
           else if (strcmp(command, "dbcls") == 0)
           {
               system("clear");
           }
           else if (strcmp(command, "man") == 0)
           {
               printf("\n'create' 'db_name': create database\n");
               printf("'update' 'db_name': update database\n");
               printf("'read' 'db_name': read database\n");
               printf("'delete' 'db_name': delete database\n");
               printf("'dbcls': clear the screen\n");
               print("'exit': Exit the program\n");
           }
           else
           {
               printf("\n Command doesn't exist\n");
           }
        }
        else if(strcmp(command, "create") == 0){
            printf("\nFile created");
        }
        else if (strcmp(command, "update") == 0)
        {
            printf("\nFile update");
        }
        else if (strcmp(command, "read") == 0)
        {
            printf("\nread file");
        }
        else if (strcmp(command, "delete") == 0)
        {
            printf("\ndelete file");
        }

           
            
        
        


        for (size_t i = 0; i < 99; i++)
        {
            input[i] = '0';
        }
        input[99] = '\0';


        
    }

    return 0;
}
