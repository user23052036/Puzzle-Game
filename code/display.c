#include"display.h"

// Function to display the 2D array in a grid format
void display(int **array, int length)
{
    // Calculate the width required for displaying numbers
    int num_width = 1;
    while(num_width < length*length)
        num_width = num_width*10;
    num_width = (int)log10(num_width);


    // Print horizontal line
    int width = length * (3 + num_width) + 1;
    printf("\n");
    for(int i=0; i<width; i++)
        printf("-");
    printf("\n");


    // Print array elements in a grid
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            if(array[i][j] !=length*length)
                printf("| %*d ", num_width, array[i][j]);   // %* allow to specify a custom width (num_width) 
            else                                            // we could have also specified big constants too
                printf("| %*s ", num_width, " ");           // Placeholder for empty cell
        }
        printf("|\n");
    }


    // Print horizontal line
    for(int i=0; i<width; i++)
        printf("-");
    printf("\n");
}
