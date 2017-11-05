#include <stdio.h>
#include <stdlib.h>
#include "compvect.h"
#include "metodo.h"
#include "obtenciondatos.h"

int main(int argc, char** argv) {
    float t_inv[6];    
    float t_ale[6];    
    int tam[] = {1000,2000,4000,8000,16000,32000};
    obtencionDatos(tam, 6,t_inv,t_ale);
    int i;
    printf("\tTiempo orden inverso \t Tiempo orden aleatorio\n");
    for(i=0;i<6;i++){
        printf("%d \t %5.4f \t\t %5.4f \n",tam[i], t_inv[i],t_ale[i]);
    }
    return (EXIT_SUCCESS);
}
