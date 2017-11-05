#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compvect.h"
#include "metodo.h"

void obtencionDatos(int tam[], int n, float t_inv[], float t_ale[]){
    int i,j;
    float count;
    for(i=0;i<n;i++){
        float tiempo;
        int vec[tam[i]];
        inicializaVector(vec,tam[i],1);
        metodo(vec, tam[i], &tiempo);
        t_inv[i] = tiempo;
    }
    for(i=0;i<n;i++){
        float tiempo2;
        for(j=0;j<10;j++){
            int vec[tam[i]];
            inicializaVector(vec,tam[i],2);
            metodo(vec, tam[i], &tiempo2);    
            count += tiempo2;
        }
        t_ale[i] = count/10;
        count = 0;
    }
}
