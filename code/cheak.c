#include"cheak.h"
#include"free.h"
#include"algorithm.h"


// Function to check if the current array matches the goal state
int match(int **array, int length)
{
    int i, j, **array1 = (int**)malloc((length)*sizeof(int*)); // Allocate memory for temporary array

    // Allocate memory for rows of the temporary array
    for(i=0; i<length; i++)
        array1[i] = (int*)malloc(length*sizeof(int));


    // Generate the goal state
    assign_num(array1, length);


    // Compare each element of the current array with the goal state
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

    // Check if all elements match
    if(i+j == length*length-2)
        return 0;                       // Success
    else 
        return 1;                       // Failure
    
    // Free memory allocated for the temporary array
    free_memory(array1, length);
}
