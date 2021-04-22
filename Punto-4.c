#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;


typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
}Cliente;

void cargar(Cliente *, int);
void cargarCliente(Cliente * , int);
void mostrar(Cliente *);
void mostrarCliente(Cliente *, int);


int main() {

    srand(time(NULL));
    Cliente *cantidadClientes;
    int cantidad;
    printf("Ingrese la cantidad de Clientes: ");
    scanf("%d", &cantidad);

    cantidadClientes = (Cliente *)malloc(sizeof(Cliente) * cantidad);

    cargarCliente(cantidadClientes, cantidad);
    mostrarCliente(cantidadClientes, cantidad);

    return 0;
}

void cargarCliente(Cliente *cargarCliente, int cantidad){

    for (int i = 0; i < cantidad; i++)
    {
        cargar(cargarCliente, i);
        cargarCliente++;
    }
}

void cargar(Cliente *cargarCliente , int n){

    char *TiposProductos[]={"Galletas","Snack","Cigarrillo","Caramelos","Bebidas"};

    char nombre[10];
    cargarCliente->ClienteID = n +1;
    printf("Ingrese nombre del cliente: ");
    fflush(stdin);
    gets(nombre);
    fflush(stdin);
    printf ("\n");
    cargarCliente->NombreCliente = (char *) malloc(sizeof(char)*strlen(nombre));
    strcpy(cargarCliente->NombreCliente, nombre);
    cargarCliente->CantidadProductosAPedir = rand() % 6 + 1;
    cargarCliente->Productos = (Producto *)malloc(sizeof(Producto)* cargarCliente->CantidadProductosAPedir);

    for (int j = 0; j < cargarCliente->CantidadProductosAPedir; j++)
    {
        cargarCliente->Productos[j].ProductoID = j + 1;
        cargarCliente->Productos[j].Cantidad = rand() % 11 + 1;
        cargarCliente->Productos[j].TipoProducto=*(TiposProductos + rand()%(5));
        cargarCliente->Productos[j].PrecioUnitario = (float) 100 + rand ()%(100+1-10);

    }
    
  
}

void mostrarCliente(Cliente * mostrarCliente, int cantidad){

    for (int i = 0; i < cantidad; i++)
    {
        mostrar(mostrarCliente);
        mostrarCliente++;
    }
    

}

void mostrar(Cliente * cargarCliente){
  
    printf("\n----------Cliente----------------\n");
    printf("ClienteID: %d\n", cargarCliente->ClienteID);
    printf("Nombre: %s\n", cargarCliente->NombreCliente);
    printf("Cantidad de Productos a pedir: %d\n", cargarCliente->CantidadProductosAPedir); 
    printf("------------Productos--------------\n");
    for ( int i = 0; i < cargarCliente->CantidadProductosAPedir; i++)
    {
        printf("--------------------------\n");
        printf("Producto ID: %d\n",cargarCliente->Productos[i].ProductoID);
        printf("Cantidad: %d\n", cargarCliente->Productos[i].Cantidad);
        printf("cantidad:%s\n", cargarCliente->Productos[i].TipoProducto);
        printf("Precio: %2.f\n", cargarCliente->Productos[i].PrecioUnitario);       
    } 
}