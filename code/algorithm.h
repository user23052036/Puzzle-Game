#ifndef ALGORITHM_H
#define ALGORITHM_H

// Standard library includes
#include<stdio.h>
#include<math.h>
#include<stdbool.h>


// Function to assign numbers to a 2D array
void assign_num(int**, int);

// Function to check boundary conditions in a 2D array
// - char direction: The direction of movement ('U', 'D', 'L', 'R')
void check_boundary(int**, int,int,char);

// Main algorithm function to manipulate a 2D array based on input
void algorithm(int**, char, int);



#endif