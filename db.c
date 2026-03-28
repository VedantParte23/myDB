#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "db.h"
#define SIZE_INPUT 125

void create_file(char *file)
{
    FILE *fp = fopen(file, "ab");

    if (fp == NULL)
    {
        fprintf(stderr, "Erorr unable to create file %s\n", file);
        return;
    }

    printf("%s was created\n", file);
    fclose(fp);
}

void write_file(char *file, Info *data, int total)
{
    FILE *fp = fopen(file, "ab");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", file);
        return;
    }

    int items = fwrite(data, sizeof(Info), total, fp);

    if (items != total)
    {
        fprintf(stderr, "Error");
    }

    printf("\nData succesfully written to file: %s\n", file);
    fclose(fp);
    
}

void update_file(char *file)
{

    FILE *fp;
    fp = fopen(file, "rb+");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", file);
    }
    int want_id;
    printf("Enter id which need to be updated: ");
    if(scanf("%d", &want_id)!= 1){
        fprintf(stderr, "Error taking input");
        return;
    }
    getchar();

    int ip, i = 0;
    Info temp;
    char new_name[50], new_info[200];
    while (fread(&temp, sizeof(Info), 1, fp) == 1)
    {
        if (temp.id == want_id) 
        {
            printf("person of id found!\n");

            printf("Enter new name: ");
            fgets(new_name, 50, stdin);
            new_name[strcspn(new_name, "\n")] = '\0';

            printf("Enter new info: ");
            fgets(new_info, 200, stdin);
            new_info[strcspn(new_info, "\n")] = '\0';

            strcpy(temp.name, new_name);
            strcpy(temp.data, new_info);

            fseek(fp, -sizeof(Info), SEEK_CUR); // does't need to multipy sizeof by i. it automaicly parses
            fwrite(&temp, sizeof(Info), 1, fp);

            printf("\nUpdated data\n");
            fclose(fp);
            return;
        }
        i++;
    }

    printf("id not found, please enter a valid id\n");
    fclose(fp);
}

void read_file(char *file, Info *data)
{

    FILE *fp = fopen(file, "rb");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found %s \n", file);
        return;
    }

    while (fread(data, sizeof(Info), 1, fp) == 1)
    {
        printf("\n-------------------------\n");
        printf("Name: %s\n", data->name);
        printf("id: %d\n", data->id);
        printf("Info: %s", data->data);
        printf("\n");
    }

    fclose(fp);
}

void delete_file(char *file)
{
    // errono shikay lagnar error specify karay

    if (remove(file) == 0)
    {
        printf("Database succesfully deleted\n");
    }
    else
    {
        fprintf(stderr, "Unable to delete/File not found %s\n", file);
    }
}

void list_files()
{

    DIR *directory;
    struct dirent *entry;

    directory = opendir(".");

    if (directory == NULL)
    {
        printf("Error opening directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            printf("Files: %s\n", entry->d_name);
        }
    }

    if (closedir(directory) == -1)
    {
        printf("Error closing the directory");
        return;
    }
}
