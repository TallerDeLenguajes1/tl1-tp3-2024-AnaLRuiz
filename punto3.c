#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char **vector;
    char *Buff;
    
    vector=(char**)malloc(sizeof(char*)*5);
    Buff=(char *) malloc(100*sizeof(char));
    printf("ingrese los nombres: \n");
    for (int i = 0; i < 5; i++)
    {
        gets(Buff);
        vector[i]=(char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(vector[i],Buff);
    }

    printf("nombres ingresados:\n");
    for (int j = 0; j < 5; j++)
    {
        puts(vector[j]);
    }
    
    free(Buff);
    for (int k = 0; k < 5; k++)
    {
        free(vector[k]);
    }
    free(vector);
    
    return 0;
}