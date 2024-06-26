#include"display.h"

// Function to display the 2D array in a grid format
void display(int **array, int length)
{
    // Print horizontal line
    printf("\n");
    for(int i=0; i<length; i++)
        printf("----");
    printf("\n");


    // Calculate the width required for displaying numbers
    int num_width = 1;
    while(num_width < length*length)
        num_width = num_width*10;
    num_width = (int)log10(num_width);


    // Print array elements in a grid
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<length; j++)
        {
            if(array[i][j] != length*length)
                printf("| %*d ",num_width,array[i][j]);   // %* the width of the filed will be taken as an arument we could have also specified big constants too
            else
                printf("|    ");                            // Placeholder for empty cell
        }
        printf("|\n");
    }


    // Print horizontal line
    for(int i=0; i<length; i++)
        printf("----");
    printf("\n");
}
