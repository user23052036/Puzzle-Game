#include"display.h"



void display(int **array, int length)
{
    printf("\n");
    for(int i=0; i<length; i++)
        printf("----");
    printf("\n");


    int num_width = 1;
    while(num_width < length*length)
        num_width *= 10;
    num_width = (int)log10(num_width);


    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            if(array[i][j] != length*length)
                printf("| %*d ", num_width, array[i][j]);       // doubt need to know more
            else
                printf("|    ");
        }
        printf("|\n");
    }

    for(int i=0; i<length; i++)
        printf("----");
    printf("\n");
}