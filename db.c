#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>
#include "db.h"
#define SIZE_INPUT 125



void create_file(char *file)
{
    FILE *fp = fopen(file, "ab");

    if (fp == NULL)
    {
        fprintf(stderr, "Erorr unable to create file %s\n",file);
        return;
    }

    printf("%s was created\n", file);
    fclose(fp);
}



bool write_file(char *file , Info *data, int total)
{
    FILE *fp = fopen(file,"ab");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n",file);
        return false;
    }
    
    int items = fwrite(data,sizeof(Info),total,fp);

    if (items != total)
    {
        fprintf(stderr, "Error");
    }
    
    printf("\nData succesfully written to file: %s\n",file);
    fclose(fp);
    return true;

}



void update_file(char *file){

    FILE *fp;
    fp = fopen(file,"rb+");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s\n",file);
    }
    int id;
    printf("Enter id which need to be updated: ");
    scanf("%d",&id);

    int ip;
    while (0)
    {
        printf("this is impossible to print");
    }
    



    printf("updated");
}

void read_file(char *file, Info *data){

    FILE *fp = fopen(file, "rb");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found %s \n",file);
        return;
    }
    
    while (fread(data,sizeof(Info),1,fp) == 1)
    {
        printf("\n-------------------------\n");
        printf("Name: %s\n",data->name);
        printf("id: %d\n",data->id);
        printf("Info: %s",data->data);
    }
    

    fclose(fp);

}

void delete_file(char *file)
{
    //errono shikay lagnar error specify karay
    
    if (remove(file) == 0)
    {
        printf("Database succesfully deleted\n");
    }
    else{
        fprintf(stderr, "Unable to delete/File not found %s\n",file);
    }

}


void list_files(){
      

    DIR *directory;
    struct dirent *entry;

    directory = opendir(".");

    if (directory == NULL)
    {
        printf("Error opening directory");
        return ;
    }

    while ((entry = readdir(directory)) != NULL)
    {
        if (entry->d_type == DT_REG)
        {
            printf("Files: %s\n",entry->d_name);
        }
        
    }
    
    if (closedir(directory) == -1)
    {
        printf("Error closing the directory");
        return ;
    }
}
