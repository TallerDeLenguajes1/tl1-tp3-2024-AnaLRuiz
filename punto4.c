#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//ESTRUCTURAS
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef DProducto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    DProducto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef DCliente;

//DECLARACION DE FUNCIONES
void CargarCliente(DCliente *clientes, int cantClientes);
void CargarProductos(DProducto *productos , int cantTipo);
float totalProducto(DProducto producto);
void mostrar (DCliente *clientes, int cantClientes);
//PROGRAMA RPINCIPAL
int main(){
    int cantClientes;
    DCliente *clientes;

    printf("Ingrese la cantidad de clientes:");
    scanf("%d", &cantClientes);
    if (cantClientes>0 && cantClientes<5){

        CargarCliente(clientes,cantClientes);
        mostrar(clientes, cantClientes);
    }else{
        printf("Ingrese una cantidad menor de 5");
    }
    
    return 0;
}
//DEFINICION DE FUNCIONES
void CargarCliente(DCliente *clientes, int cantClientes){
    char *buff;
    buff=(char *)malloc(sizeof(char)*100);
    srand(time(NULL));
    for (int i = 0; i < cantClientes; i++)
    {
        clientes->ClienteID=i;

        printf("\nNombre del cliente %d: ", clientes->ClienteID);
        fflush(stdin);
        gets(buff);
        clientes->NombreCliente=(char *)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(clientes->NombreCliente,buff);

        clientes->CantidadProductosAPedir=1+rand()%5;
        int cantTipo=clientes->CantidadProductosAPedir;

        clientes->Productos=(DProducto *)malloc(cantTipo*sizeof(DProducto));
        CargarProductos(clientes->Productos,cantTipo);
        clientes++;
    }
}
void CargarProductos(DProducto *productos , int cantTipo){
    for (int j = 0; j < cantTipo; j++)
    {
        
        productos->ProductoID=j;
            
        printf("\nCantidad de producto: ");
        scanf("%d",&productos->Cantidad);
        
        int tipo;
        printf("\nTipo de producto(0-Galletas , 1-Snack, 2-Cigarrillos , 3-Caramelos, 4-Bebidas): ");
        scanf("%d", &tipo);
        productos->TipoProducto=(char *)malloc((strlen(TiposProductos[tipo])+1)*sizeof(char));
        strcpy(productos->TipoProducto, TiposProductos[tipo]);

        productos->PrecioUnitario=10+rand()%109;
            
        productos++;
    }
}
float totalProducto(DProducto producto){
    float total;
    total=producto.Cantidad*producto.PrecioUnitario;
    return total;
}
void mostrar (DCliente *clientes, int cantClientes){
    printf("\n***********datos ingresados*************");
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\nDatos del cliente %d", clientes->ClienteID);
        printf("\nNombre:");
        puts(clientes->NombreCliente);
        printf("\ncantidad de productos a pedir: %d", clientes->CantidadProductosAPedir);
        printf("\nDatos de los productos: \n");
        for (int j = 0; j < clientes->CantidadProductosAPedir; j++)
        {
            printf("\nproducto %d:", clientes->Productos->ProductoID);
            printf("\nCantidad: %d",clientes->Productos->Cantidad);
            printf("\nTipo de producto:");
            puts(clientes->Productos->TipoProducto);
            printf("\nPrecio unitario: %.2f", clientes->Productos->PrecioUnitario);
            printf("\nTotal: %.2f", totalProducto(clientes->Productos[i]));
            clientes->Productos++;
        }
        clientes++;
    }
    
}