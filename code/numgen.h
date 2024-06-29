#ifndef NUMGEN_H
#define NUMGEN_H

// Standard library includes
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>


// Function to assign random unique numbers to a 2D array
void random_assign(int**, int, int, int);

// Function to check if a number is unique in the array up to a given position
bool is_unique(int**, int, int, int, int);


#endif