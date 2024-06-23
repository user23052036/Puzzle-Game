#include"algorithm.h"
#include"free.h"


void assign_num(int **ptr, int length)
{
    int num=1;

    for(int i=0; i<length; i++)
        for(int j=0; j<length; j++)
            {
                ptr[i][j] = num;
                num++;
            }
}


void check_boundary(int **array, int length)
{
    int i,j;
    for(i=0; i<length; i++)
    {
        for(j=0; j<length; j++)
            if(array[i][j] == length*length)
                break;

        if(array[i][j] == length*length)
            break;
    }

    if(array[i][j] != length*length)
    {
        printf("\n You have entered an invalid input");
        free_memory(array,length);
        exit(0);
    }
}


void algorithm(int **array, char direction, int length)
{
    int row, column;

    for(row=0; row<length; row++)
    {
        for(column=0; column<length; column++)
            if(array[row][column] == length*length)
                break;
        if(array[row][column] == length*length)
        break;
    }

    switch(direction)
    {
        case 'a':
        case 'A':
        {
            array[row][column] = array[row][column] + array[row][column+1];
            array[row][column+1] = array[row][column] - array[row][column+1];
            array[row][column] = array[row][column] - array[row][column+1];

            check_boundary(array,length);
            break;
        }

        case 'd':
        case 'D':
        {
            array[row][column] = array[row][column] + array[row][column-1];
            array[row][column-1] = array[row][column] - array[row][column-1];
            array[row][column] = array[row][column] - array[row][column-1];

            check_boundary(array,length);
            break;
        }

        case 's':
        case 'S':
        {
            array[row][column] = array[row][column] + array[row-1][column];
            array[row-1][column] = array[row][column] - array[row-1][column];
            array[row][column] = array[row][column] - array[row-1][column];

            check_boundary(array,length);
            break;
        }

        case 'w':
        case 'W':
        {
            array[row][column] = array[row][column] + array[row+1][column];
            array[row+1][column] = array[row][column] - array[row+1][column];
            array[row][column] = array[row][column] - array[row+1][column];

            check_boundary(array,length);
            break;
        }

        default:
        {
            printf("Enter a valid move and TRY AGAIN");
            free_memory(array,length);
            exit(0);
        }
    }
}