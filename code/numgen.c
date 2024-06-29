#include "numgen.h"

// Assigns random unique numbers to a 2D array
void random_assign(int **array, int min, int max, int length) 
{
    int rand_num, seed = time(NULL) * getpid();
    srand(seed);

    for(int i = 0; i < length; i++) 
    {
        for(int j = 0; j < length; j++) 
        {
            do 
            {
                rand_num = (rand() % (max - min + 1)) + min;
                array[i][j] = rand_num;
            } while (!is_unique(array, length, i, j, rand_num));
        }
    }
}

// Checks if a number is unique in the array up to a given position
bool is_unique(int **array, int length, int i, int j, int rand_num) 
{
    for(int k = 0; k < length; k++) 
    {
        for(int l = 0; l < length; l++) 
        {
            if(k == i && l == j)
                return true;

            else if(array[k][l] == rand_num)
                return false;
        }
    }
    return true;
}
