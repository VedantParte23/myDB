#include <stdio.h>
#include <string.h>
#define SIZE_INPUT 125

void create_file(char *file)
{
    FILE *fp = fopen(file, "ab");

    if (fp == NULL)
    {
        fprintf(stderr, "Erorr unable to create file",file);
        return;
    }

    printf("File %s was created\n", file);
    fclose(fp);
}

void write_file(char *file)
{
    FILE *fp = fopen(file,"ab");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found", file);
    }
    char data_input[SIZE_INPUT];
    fgets(data_input,sizeof(data_input),file);
    

    fprintf(file,"%s",data_input);

    printf("Data written to %s\n",file);

    //structre cha format madhe data input karay lagnar


}

update_file(){
    //temprary file skikay lagnar 
}

void read_file(char *file)
{

    FILE *fp = fopen(file, "rb");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found",file);
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
        fprintf(stderr, "Unable to delete/File not found\n");
    }

}
