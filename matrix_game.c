#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<stdbool.h> 
#include<time.h>

void random_assign(int**, int, int, int);
int match(int**, int);
void display(int**, int);
void algorithm(int**, char, int);
void assign_num(int**, int);
void check_boundary(int**, int);
void free_memory(int**, int);
bool is_unique(int**, int, int, int, int);


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

    printf("PRESS (1) FOR EASY (3×3) \n");
    printf("PRESS (2) FOR MEDIUM (4×4) \n");
    printf("PRESS (3) FOR HARD (5×5) \n\n");
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

        printf("Lets play the GAME Enter any character to start ::--->  ");
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


int match(int **array, int length)
{
    int i,j,**array1 = (int**)malloc((length)*sizeof(int*));

    for(i=0; i<length; i++)
        array1[i] = (int*)malloc(length*sizeof(int));

    assign_num(array1,length);

    for(i=0; i<length; i++)
    {
        for(j=0; j<length; j++)
        {
            if(array[i][j] == array1[i][j])
                continue;
            else
                break;
        }
        if(array[i][j] != array1[i][j])
            break;
    }

    if(i+j == length*length-2)
        return 0;                                //success
    else 
        return 1;                                //failure
    
    free_memory(array1,length);
}


void random_assign(int **array, int min, int max, int length) // arr(address) is passed to a array of pointers (*arr)[0],(*arr)[1],(*arr)[2]
{
    int rand_num, seed =  time(NULL)*getpid(); // getpid() outputs unique process id ... every time the program runs it returns unique process ID
    bool unique;
    srand(seed);

    for(int i=0; i<length; i++)
        for(int j=0; j<length; j++)
        {
            do
            {
                rand_num = (rand() % (max-min+1)) + min;      // remainder min,min+1,min+2 ..... max
                array[i][j] = rand_num;

            }while(! is_unique(array,length,i,j,rand_num));
        }
    
}


bool is_unique(int **array, int length, int i, int j, int rand_num)
{
    for(int k=0; k<length; k++)
    {
        for(int l=0; l<length; l++)
        {
            if(k==i && l==j)
                return true;      
            else if(array[k][l] == rand_num)
                return false;
        }
    }
}


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


void free_memory(int **array, int length)
{
    for(int i=0; i<length; i++)
        free(array[i]);
    free(array);
}