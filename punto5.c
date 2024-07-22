#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    char **vector;
    char *Buff;
    int cantidadNombres;
    
    printf("Cantidad de nombres a ingresar: ");
    scanf("%d",&cantidadNombres);
    
    vector=(char**)malloc(sizeof(char*)*cantidadNombres);
    Buff=(char *) malloc(100*sizeof(char));
    printf("\ningrese los nombres: \n");
    for (int i = 0; i < cantidadNombres; i++)
    {
        fflush(stdin);
        gets(Buff);
        vector[i]=(char *)malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(vector[i],Buff);
    }

    printf("nombres ingresados:\n");
    for (int j = 0; j < cantidadNombres; j++)
    {
        puts(vector[j]);
    }
    free(Buff);
    for (int k = 0; k < cantidadNombres; k++)
    {
        free(vector[k]);
    }
    free(vector);
    
    return 0;
}