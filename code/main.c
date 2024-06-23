#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<stdbool.h> 
#include<time.h>

#include"numgen.h"
#include"display.h"
#include"algorithm.h"
#include"cheak.h"
#include"free.h"

int main()
{
    int level,moves,length,last_num;
    char direction,choice,sub_level[10];

    printf("                      !  GAME !  \n");
    printf("_________________________________________________________\n\n");
    printf("              INSTRUCTIONS GIVEN BELOW \n\n");
    printf("1. press (D) to move right  \n");
    printf("2. press (A) to move left   \n");
    printf("3. press (w) to move up     \n");
    printf("2. press (s) to move down   \n\n");


    printf("PRESS (1) FOR LEVEL-1 [40 moves]\n");
    printf("PRESS (2) FOR LEVEL-2 [30 moves]\n");
    printf("PRESS (3) FOR LEVEL-3 [20 moves]\n\n");
    printf("Choose the level at which you want to play the game :: --->");
    scanf("%d",&level);

    printf("TYPE EASY FOR EASY LEVEL (3*3) \n");
    printf("TYPE MEDIUM FOR MEDIUM LEVEL (4*4) \n");
    printf("TYPE HARD FOR HARD LEVEL (5*5) \n\n");
    printf("Choose the level at which you want to play the game :: --->");
    scanf("%s",&sub_level);

    while(1)
    {   
        switch(level)
        {
            case 1:
                moves = 40;
                break;

            case 2:
                moves = 35;
                break;

            case 3:
                moves = 30;
                break;
        }

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
        }

        printf("Below is the winning position need to be achieved to win the game\n\n");
        int **array = (int**)malloc(length*sizeof(int*));  

        for(int i=0; i<length; i++)
            array[i] = (int*)malloc(length*sizeof(int));    
        
        assign_num(array,length);                        
        display(array,length);

        while(getchar() != '\n'){}

        printf("Lets play the GAME press enter to start ::--->  ");
        getchar();
        
        random_assign(array,1,length*length,length);
        system("clear");
        display(array,length);

        while(moves)
        {
            printf("play your move:-> ");
            scanf("%c",&direction);

            getchar();
            system("clear");
            algorithm(array,direction,length);
            
            printf("moves left:--->  (%d) \n\n",moves);
            display(array,length);

            if(match(array,length) == 0)
                {
                    printf("\n\t\t You have won the game by only %d moves CONGRATULATIONS! \n",moves);
                    printf("Wanna move to next level press (y) else press (n) :--->");
                    scanf("%c",&choice);

                    if((choice == 'y' || choice == 'Y'))
                    {
                        if((level<4) && (length<5))
                        {
                            length++;
                            printf("you moved to the (%d×%d) level\n",length,length);
                        }
                        else if(level == 3 && length == 5)
                        {
                            printf("Congratulations you have COMPLETED THE GAME !!!");
                            break;
                        }
                        else if(length == 5)
                        {
                            level++;
                            length = 3;
                            printf("you moved to the %d level and (%d×%d) sub-level\n",level,length,length);
                        }
                    }
                    else
                        break;
                }
            moves--;
        }
        if(moves == 0)
        {
            printf("\n\t\t LOST !!!! TRY AGAIN ");
            break;
        }
        free_memory(array,length);
        return 0;
    }
}