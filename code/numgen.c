#include"numgen.h"


void random_assign(int **array, int min, int max, int length) // arr(address) is passed to a array of pointers (*arr)[0],(*arr)[1],(*arr)[2]
{
    int rand_num, seed =  time(NULL)*getpid(); // getpid() outputs unique process id ... every time the program runs it returns unique process ID
    bool unique;
    srand(seed);

    for(int i=0; i<length; i++)
        for(int j=0; j<length; j++)
        {
            do
            {
                rand_num = (rand() % (max-min+1)) + min;      // remainder min,min+1,min+2 ..... max
                array[i][j] = rand_num;

            }while(! is_unique(array,length,i,j,rand_num));
        }
    
}


bool is_unique(int **array, int length, int i, int j, int rand_num)
{
    for(int k=0; k<length; k++)
    {
        for(int l=0; l<length; l++)
        {
            if(k==i && l==j)
                return true;      
            else if(array[k][l] == rand_num)
                return false;
        }
    }
}