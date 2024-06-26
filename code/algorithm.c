#include"algorithm.h"
#include"free.h"

// Function to assign numbers to the puzzle grid
void assign_num(int **ptr, int length)
{
    int num=1;

    // Fill the grid with numbers in sequential order
    for(int i=0; i<length; i++)
        for(int j=0; j<length; j++)
            {
                ptr[i][j] = num;
                num++;
            }
}

// Function to check if the boundary condition is violated
void check_boundary(int **array, int row, int column, char move)
{
    bool flag=false;
    int length = sqrt(array[row][column]);

    if(move == 'd' && column-1 >= 0)
        flag = true;

    else if(move == 'a' && column+1 <= length-1)
        flag = true;

    else if(move =='w' && row+1 <= length-1)
        flag = true;

    else if(move == 's' && row-1 >= 0)
        flag = true;
    
    if(flag == false)
    {
        printf("YOU LOST AS YOU ENTERED AN INVALID MOVE !!\n");
        printf("Better luck next time !\n\n");
        free_memory(array,length);
        exit(0);
    }
}


// Function to perform the move based on user input
void algorithm(int **array, char direction, int length)
{
    int row, column; 
    for(row=0; row<length; row++)                   // Find the position of the empty cell
    {
        for(column=0; column<length; column++)
            if(array[row][column] == length*length)
                break;
        if(array[row][column] == length*length)
            break;
    }

    // Perform the move based on user input
    switch(direction)
    {
        case 'a':
        case 'A':
        {
            check_boundary(array,row,column,'a');

            array[row][column] = array[row][column] + array[row][column+1];
            array[row][column+1] = array[row][column] - array[row][column+1];
            array[row][column] = array[row][column] - array[row][column+1];
            break;
        }

        case 'd':
        case 'D':
        {
            check_boundary(array,row,column,'d');
                
            array[row][column] = array[row][column] + array[row][column-1];
            array[row][column-1] = array[row][column] - array[row][column-1];
            array[row][column] = array[row][column] - array[row][column-1];
            break;
        }

        case 's':
        case 'S':
        {
            check_boundary(array,row,column,'s');

            array[row][column] = array[row][column] + array[row-1][column];
            array[row-1][column] = array[row][column] - array[row-1][column];
            array[row][column] = array[row][column] - array[row-1][column];
            break;
        }

        case 'w':
        case 'W':
        {
            check_boundary(array,row,column,'w');

            array[row][column] = array[row][column] + array[row+1][column];
            array[row+1][column] = array[row][column] - array[row+1][column];
            array[row][column] = array[row][column] - array[row+1][column];
            break;
        }

        default:
        {
            printf("YOU LOST AS YOU ENTERED AN INVALID MOVE !!\n");
            printf("Better luck next time !\n\n");
            free_memory(array,length);
            exit(0);
        }
    }
}
