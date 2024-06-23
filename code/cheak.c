#include"cheak.h"
#include"free.h"


int match(int **array, int length)
{
    int i,j,**array1 = (int**)malloc((length)*sizeof(int*));

    for(i=0; i<length; i++)
        array1[i] = (int*)malloc(length*sizeof(int));

    assign_num(array1,length);

    for(i=0; i<length; i++)
    {
        for(j=0; j<length; j++)
        {
            if(array[i][j] == array1[i][j])
                continue;
            else
                break;
        }
        if(array[i][j] != array1[i][j])
            break;
    }

    if(i+j == length*length-2)
        return 0;                                //success
    else 
        return 1;                                //failure
    
    free_memory(array1,length);
}