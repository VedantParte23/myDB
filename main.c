#include <stdio.h>
#include <string.h>


struct student
{
    char name[30];
    int id;
    
};


int main(){
    char input[20];

    
    

    while (1)
    {
        printf("VedDB> ");
        scanf("%s",&input);

        if (strcmp(input,"create")== 0)
        {
            printf("\nFile created\n");
        }
        else if (strcmp(input,"update")== 0)
        {
            printf("\nFile updated\n");
        }
        else if (strcmp(input,"read")== 0)
        {
            printf("\nFile read\n");
        }
        else if (strcmp(input,"delete")== 0)
        {
            printf("\nFile delete\n");
        }
        else{
            printf("\n Command doesn't exist");
        }

        for (size_t i = 0; i < 20; i++)
        {
            input[i] = '0';
        }
        
        

    }
    

    return 0;
}
