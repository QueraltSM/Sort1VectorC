#include <stdio.h>
#include <stdlib.h>
   void inicializaVector(int vec[],int n,int orden)
   {
      int i;
      switch(orden)
      {
         case 0: /* orden ascendente */
            for(i=0;i<n;i++) vec[i]=i;
            break;
         case 1: /* orden descendente */
            for(i=0;i<n;i++) vec[i]=n-i-1;
            break;
         case 2: /* orden aleatorio */
            for(i=0;i<n;i++) vec[i]=i;
            for(i=0;i<n;i++) /* Intercambiamos aleatoriamente n parejas de datos */
            {
               int aux, pos;
               pos = rand()%n;
               aux = vec[i];
               vec[i] = vec[pos];
               vec[pos] = aux;
            }
            break;
         default:
            printf("inicializaVector: Parametro 'orden' erróneo\n");
            printf("inicializaVector: Valores aceptados:  0 ascendente, 1:descendente y 2:aleatorio\n");
            exit(0);
      }
   }

   void compruebaVector(int vec[],int n)
   {
      int i,desordenes;
      char *aux;
      for(desordenes=0,i=1;i<n;i++) /* calcula el número de elementos desordenados */
         if(vec[i]<vec[i-1]) desordenes++;
      if(!desordenes)
      {
         int faltan;
         for(faltan=0,i=0;i<n;i++) /* calcula el número de elementos que faltan */
            if(vec[i] != i) faltan++;
         if(!faltan) 
            return; /* Ordenacíon correcta */
      }
      else
      {
         printf("compruebaVector: Vector de %d elementos desordenado\n",n);
         printf("compruebaVector: Se ha(n) encontrado %d posición(es) desordenada(s)\n",desordenes);
      }
      aux = (char *) malloc(n*sizeof(char));
      if(aux != NULL)
      {
         int faltan=0, sobran=0;
         for(i=0;i<n;i++)	aux[i]=0;
         for(i=0;i<n;i++)
            if((vec[i] >= 0) && (vec[i] < n))
               aux[vec[i]]=1; /* vec[i] está */
            else
               sobran++;  /* vec[i] tiene un valor fuera de rango */
         for(i=0;i<n;i++) /* cuenta los no encontrados */
            if(aux[i] == 0 ) faltan++;
         if(faltan)
         {
            printf("compruebaVector: Error en los datos\n");
            printf("compruebaVector: Falta(n) %d elemento(s)\n",faltan);
         }
         if(sobran)
            printf("compruebaVector: %d elemento(s) esta(n) fuera de rango\n",sobran);
         free(aux);
      }
      else
      {
         printf("compruebaVector: No hay suficiente memoria para comprobar en detalle los datos\n");
         if(!desordenes)
            printf("compruebaVector: Error en los datos\n");
      }
   }