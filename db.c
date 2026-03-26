#define _DEFAULT_SOURCE
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#define SIZE_INPUT 125

typedef struct 
{
    char name[50];
    int id;
    char data[200];
}info;



void create_file(char *file)
{
    FILE *fp = fopen(file, "ab");

    if (fp == NULL)
    {
        fprintf(stderr, "Erorr unable to create file %s\n",file);
        return;
    }

    printf("DB %s was created\n", file);
    fclose(fp);
}

void write_file(char *file)
{
    FILE *fp = fopen(file,"ab");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found %s\n", file);
        return;
    }
    char data_input[SIZE_INPUT];
    fgets(data_input,sizeof(data_input),stdin);
    

    fprintf(fp,"%s",data_input);

    printf("Data written to %s\n",file);

    //structre cha format madhe data input karay lagnar
    fclose(fp);

}

void update_file(){
    //temprary file skikay lagnar 
}

void read_file(char *file)
{

    FILE *fp = fopen(file, "rb");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found %s \n",file);
        return;
    }
    
    char ch;
    printf("Contents of %s: ",file);
    printf("\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
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
            printf("Files: %s",entry->d_name);
        }
        
    }
    
    if (closedir(directory) == -1)
    {
        printf("Error closing the directory");
        return ;
    }
}
