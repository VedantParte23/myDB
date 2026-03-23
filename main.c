#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "db.h"

#define SIZE 100


struct student
{
    char name[30];
    int id;
    char info[100];
};



int main()
{
    char input[SIZE+1];

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
           else if (strcmp(command, "ls") == 0)
           {
               printf("The files are: \n");
           }
           else if (strcmp(command, "man") == 0)
           {
               printf("\n'create' 'db_name': create database\n");
               printf("'write' 'db_name': write in database\n");
               printf("'read' 'db_name': read database\n");
               printf("'delete' 'db_name': delete database\n");
               printf("'ls': list the file in directory\n");
               printf("'dbcls': clear the screen\n");
               printf("'exit': Exit the program\n");
           }
           else
           {
               printf("\nadd a filename/argument to the command\n");
           }
        }
        else if(strcmp(command, "create") == 0){
            printf("\nDatabase created\n");
        }
        else if (strcmp(command, "write") == 0)
        {
            printf("\nUpdate Database\n");
        }
        else if (strcmp(command, "read") == 0)
        {
            printf("\nRead Database\n");
        }
        else if (strcmp(command, "delete") == 0)
        {
            printf("\nDatabase Deleted\n");
        }

           
            
        
        


        for (size_t i = 0; i < 100; i++)
        {
            input[i] = '0';
        }
        input[100] = '\0';


        
    }

    return 0;
}
