#include <stdio.h>
#include <stdlib.h>
#include "obtenciondatos.h"
#include "compvect.h"
#include "metodo.h"

void obtencionDatos(int tam[], int n, float t_inv[],  float t_ale[])
{
    
    // arrays es un puntero a puntero de enteros
    int **arrays;
    
    // reserva espacio para n punteros a enteros
    arrays=(int **) malloc (n*sizeof(int*));
    
    int j;
    for (j=0; j<n;j++)
    {
        t_ale[j] = 0.0;
        t_inv[j] = 0.0;
    }
    
    int i = 1000;
    j = 0;
    while (n>j)
    {
        arrays[j]=(int *) malloc(i*sizeof(int));
        j++;
        i *=2;
    }
    
    for (i = 0; i<n; i++)
    {
        // Calcula tiempo para vectores de orden inverso
        inicializaVector(arrays[i], tam[i], 1);
        metodo(arrays[i], tam[i], &t_inv[i]);
        compruebaVector(arrays[i], tam[i]);
        
        // Calcula tiempo para vectores de orden aleatorio
        for (j=0; j<10; j++)
        {
            inicializaVector(arrays[i], tam[i], 2);
            metodo(arrays[i], tam[i], &t_ale[i]);
            compruebaVector(arrays[i], tam[i]);
            
        }
        t_ale[i] /= 10.0f;
    }
    
}