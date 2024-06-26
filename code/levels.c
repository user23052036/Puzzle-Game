#include"levels.h"


bool move_next_level(int *moves, int *level, int *length, char choice)
{
    if((choice == 'y' || choice == 'Y'))
    {
        if(*level==1 && *length<5)
        {
            (*length)++;
            *moves=60;
            printf("you are in %d level the (%d×%d)- sub-level\n\n",*level,*length,*length);
            return true;
        }
        else if(*level==1 && *length==5)
        {
            (*level)++;
            *moves=55;
            *length=3;
            printf("you moved to %d level the (%d×%d)- sub-level\n\n",*level,*length,*length);
            return true;
        }
        else if(*level==2 && *length<5)
        {
            (*length)++;
            *moves=55;
            printf("you are in %d level the (%d×%d)- sub-level\n\n",*level,*length,*length);
            return true;
        }
        else if(*level==2 && *length==5)
        {
            (*level)++;
            *moves=50;
            *length=3;
            printf("you moved to %d level the (%d×%d)- sub-level\n\n",*level,*length,*length);
            return true;
        }
        else if(*level==3  && *length<5)
        {
            (*length)++;
            *moves=50;
            printf("you are in %d level the (%d×%d)- sub-level\n\n",*level,*length,*length);
            return true;
        }
        else if(*level==3 && *length==5)
        {
            printf("YOU COMPLETED ALL THE LEVELS OF THE GAME CONGRAGULATIONS !\n\n");
            return false;
        }
    }

    printf("Thanks For playing the game!\n\n");
    return false;
}