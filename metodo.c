#include <time.h>
#include "metodo.h"
void metodo(int vec[], int n, float *tiempo)
{
	int tmp;
	int i,j;
    clock_t ini = clock();
	
	for (i = 0; i< n-1; i++)
    {
		for(j = i+1; j<n;j++)
        {
			if(vec[j] < vec[i])
            {
				tmp = vec[i];
				vec[i]=vec[j];
				vec[j]=tmp;
			}
		}
	}
    *tiempo += (float)(clock() - ini) / (float) CLOCKS_PER_SEC;
}