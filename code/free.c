#include"free.h"


void free_memory(int **array, int length)
{
    for(int i=0; i<length; i++)
        free(array[i]);
    free(array);
}