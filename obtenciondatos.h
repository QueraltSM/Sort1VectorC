#ifndef INC_COMPVECT
#define INC_COMPVECT
/**********************************************************************/
/* InicializaVector es un procedimiento que inicializa un vector de   */
/* n elementos en el orden solicitado.                                */
/* Parámetros:                                                        */
/* vec   : vector de entero de n elemetos a inicializar.              */
/* n     : número de elementos a inicializar de Vec.                  */
/* orden : orden con que queremos que se inicialice Vec.              */
/*         0 => orden ascendente.                                     */
/*         1 => orden descendente.                                    */
/*         2 => aleatorio.                                            */
/**********************************************************************/

void inicializaVector(int vec[],int n,int orden);

/**********************************************************************/
/* compruebaVector es un procedimiento que comprueba el orden y       */
/* consistencia de un vector de n elementos ordenado y previamente    */
/* inicializado con inicializaVector.                                 */
/* El procedimiento comprueba el orden y que están todos los          */
/* elementos con que se inicializo el vector.                         */
/* Parámetros:                                                        */
/* vec   : vector de entero de n elemetos a comprobar.                */
/* n     : número de elementos ordenados de vec.                      */
/**********************************************************************/

void compruebaVector(int vec[],int n);

#endif