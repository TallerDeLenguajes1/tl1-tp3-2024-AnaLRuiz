#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define I 5
#define J 12
/*Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:*/
int main(){
    int arre[I][J];
    int num;
    /*Cargue dicha matriz con valores aleatorios entre 10000 y 50000.*/
    srand(time(NULL));
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            num=rand()%40001+10000;
            arre[i][j]=num;
        }
    }
    /*Muestre por pantalla los valores cargados*/
    printf("========PRODUCCION MENSUAL DE 5 ANIOS=======\n");
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            printf("%d\t",arre[i][j]);
        }
        printf("\n");
    }
    /*Saque el promedio de ganancia por año y muestrelos por pantalla*/
    float suma=0, promedio[I];
    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            suma=arre[i][j]+suma;
        }
        promedio[i]=suma/J;
    }
    printf("\n=========PROMEDIO DE GANACIA POR AÑO==========\n");
    for (int i = 0; i < I; i++)
    {
        printf("anio %d : %.2f\n",i+1,promedio[i]);
    }
    /*Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.*/
    int mayor=0, anioMayor, mesMayor;
    int menor=arre[0][0], anioMenor, mesMenor;

    for (int i = 0; i < I; i++)
    {
        for (int j = 0; j < J; j++)
        {
            if (mayor<arre[i][j])
            {
                mayor=arre[i][j];
                anioMayor=i+1;
                mesMayor=j+1;
            }
            if (menor>=arre[i][j])
            {
                menor=arre[i][j];
                anioMenor=i+1;
                mesMenor=j+1;
            }
        }
    }
    printf("\n======Maxima y Minima Produccion=========\n");
    printf("El valor maximo es: %d del mes %d del anio %d\n",mayor, mesMayor, anioMayor);
    printf("El valor minimo es: %d del mes %d del anio %d\n",menor, mesMenor, anioMenor);
    
    return 0;
}