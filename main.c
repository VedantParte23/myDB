#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "db.h"

#define SIZE 100

int main(){

    
    char input[SIZE + 1];

    while (1)
    {
        printf("myDB> ");
        fgets(input, 100, stdin);
        fflush(stdout);

        char *command = strtok(input, " \n");
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
            else if (strcmp(command, "lf") == 0)
            {
                printf("The files are: \n");
                list_files();
            }
            else if (strcmp(command, "man") == 0)
            {
                printf("\n'create' 'db_name': create database\n");
                printf("'write' 'db_name': write in database\n");
                printf("'read' 'db_name': read database\n");
                printf("'delete' 'db_name': delete database\n");
                printf("'lf': list the file in directory\n");
                printf("'dbcls': clear the screen\n");
                printf("'exit': Exit the program\n");
            }
            else
            {
                printf("\nAdd a filename/argument to the command\n");
            }
        }
        else if (strcmp(command, "create") == 0)
        {
            create_file(argument);
        }
        else if (strcmp(command, "update") == 0){
            //update code will go there also need to wrtie in in man
            continue;
        }
        else if (strcmp(command, "write") == 0)
        {
            int num_oargs, id_input;
            Info temp;
            printf("\nHow many peoples information are you going to fill: ");
            if(scanf("%d",&num_oargs) != 1){
                fprintf(stderr,"Error reading input. please use proper format");
                while(getchar() != '\n');
                continue;
            }
            getchar();
            


            for (int i = 0; i < num_oargs; i++)
            {
                printf("Enter name: ");
                fgets(temp.name, 50, stdin);
                temp.name[strcspn(temp.name, "\n")] = '\0';//removes \n. continious input ghetay

                printf("Enter the id of the person: ");
                scanf("%d", &temp.id);
                getchar();

                printf("Enter information about the person: ");
                fgets(temp.data,200, stdin);
                temp.data[strcspn(temp.name,"\n")] = '\0';

                write_file(argument, &temp, 1);

            }
            

          

        }
        else if (strcmp(command, "read") == 0)
        {
            read_file(argument);
        }
        else if (strcmp(command, "delete") == 0)
        {
            delete_file(argument);
        }

        for (size_t i = 0; i < 100; i++)
        {
            input[i] = '0';
        }
        input[100] = '\0';
    }

    return 0;
}
