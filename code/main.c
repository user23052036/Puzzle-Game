//author user23052036(nomad2036)
//https://github.com/user23052036
//       Puzzle-Game

//standard library includes
#include <ctype.h>
#include<math.h>
#include<stdbool.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

//self defined header files
#include"algorithm.h"
#include"cheak.h"
#include"display.h"
#include"free.h"
#include "getkey.h"
#include"levels.h"
#include"numgen.h"


//main function
int main(void)       
{

    int level, moves, length;
    char direction, choice, sub_level[10];

    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    char *current_time = asctime(local_time);

    // Display game instructions and level selection
    system("cls");
    printf("\n\n\n\t\t\t! GAME !\n");
    printf("\t\t%s\n",current_time);
    printf("_________________________________________________________\n\n");
    printf("              INSTRUCTIONS GIVEN BELOW \n\n");
    printf("1. press (D) to move right  \n");
    printf("2. press (A) to move left   \n");
    printf("3. press (w) to move up     \n");
    printf("4. press (s) to move down   \n\n");


    // Main loop to handle game sub-levels
    while(1)
    {
        printf("PRESS (1) FOR LEVEL-1 [60 moves]\n");
        printf("PRESS (2) FOR LEVEL-2 [55 moves]\n");
        printf("PRESS (3) FOR LEVEL-3 [50 moves]\n\n");
        printf("Choose the level at which you want to play the game :: --->");
        scanf("%d",&level);

        // Set number of moves based on the selected level
        switch(level)
        {
            case 1:
                moves = 60;
                break;

            case 2:
                moves = 55;
                break;

            case 3:
                moves = 50;
                break;

            default:
            {
                printf("Please enter a valid level !\n\n");
                system("cls");
                continue;
            }
        }
        break;
    }

    // Main loop to handle game sub-levels
    while(1)
    {
        printf("\n\nTYPE EASY FOR EASY LEVEL (3*3) \n");
        printf("TYPE MEDIUM FOR MEDIUM LEVEL (4*4) \n");
        printf("TYPE HARD FOR HARD LEVEL (5*5) \n\n");
        printf("Choose the level at which you want to play the game :: --->");
        scanf("%s",sub_level);
            switch(sub_level[0])
        {
            case 'E':
            case 'e':
                length = 3;
                break;

            case 'M':
            case 'm':
                length = 4;
                break;

            case 'H':
            case 'h':
                length = 5;
                break;
                
            default:
            {
                printf("Please enter a valid sub-level !\n\n");
                system("cls");
                continue;
            }
        }
        break;
    }

      
      
    printf("Below is the winning position need to be achieved to win the game\n\n");
    int **array = (int**)malloc(length*sizeof(int*));  

    for(int i=0; i<length; i++)
        array[i] = (int*)malloc(length*sizeof(int));    
    
    assign_num(array,length);                        
    display(array,length);

    // Clear input buffer
    while(getchar() != '\n'){}

    // Start the game
    printf("Lets play the GAME press (enter) to start ::--->  ");
    getchar();
    
    random_assign(array,1,length*length,length);
    system("cls");

    // Gameplay loop
    while(moves--)
    {
        printf("-----Puzzle-Game-------\n");
        printf("moves left:--->  (%d) \n",moves+1);

        display(array,length);
        printf("play your move:-> ");
        /* scanf("%s",key_pressed);

        // Get key pressed.
        if (toupper(key_pressed[0]) == 'A' || toupper(key_pressed[0]) == 'S' || 
        toupper(key_pressed[0]) == 'D' || toupper(key_pressed[0]) == 'W')
        direction = key_pressed[0];
        // Arrow keys are converted into ^[[A, [[B, [[C, [[C on linux. ^[ = Esc.
        else if (toupper(key_pressed[0]) == 27 || toupper(key_pressed[1]) == '[')     // 27 = Esc
        {
            if (toupper(key_pressed[2]) == 'A')
                direction = 'w';
            else if (toupper(key_pressed[2]) == 'B')
                direction = 's';
            else if (toupper(key_pressed[2]) == 'C')
                direction = 'd';
            else if (toupper(key_pressed[2]) == 'D')
                direction = 'a';
        } */
       direction = get_key_pressed();


        system("cls");
        algorithm(array,direction,length);

        // Check if the player has won
        if(match(array,length) == 0)
        {
            printf("\n\t\t You have won the game by only %d moves CONGRATULATIONS! \n",moves);
            printf("Wanna move to next level press (y) else press (n) :--->");
            scanf("%c",&choice);

            if(move_next_level(&moves,&level,&length,choice) == true)
                continue;
            else
            {
                if(level==3 && length==5)
                break;
            }
        }
    }
    // Display message if the player lost
    if(moves == 0)
        printf("\n\t\t LOST !!!! TRY AGAIN ");

    // Free memory allocated for the array
    free_memory(array,length);
    return 0;
}
