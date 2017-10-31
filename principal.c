#include <stdio.h>
#include <stdlib.h>
#include "obtenciondatos.h"

int main()
{
   
    int tam[] = {1000, 2000, 4000, 8000, 16000, 32000};
    float *t_inv = (float*) malloc (6*sizeof(float));
    float *t_ale = (float*) malloc (6*sizeof(float));
    obtencionDatos(tam, 6, t_inv, t_ale);
    
    printf("      Tiempo del vector en orden inverso   Tiempo del vector en orden aleatorio\n\n");
    int i;
    for(i = 0;i<6;i++)
    {
        if (tam[i]<10000)
            printf(" ");
        printf("%d%35.5f%39.5f\n",tam[i],t_inv[i],t_ale[i]);
    }
    
    free (t_inv);
    free (t_ale);
    
    return 0;
    
}

