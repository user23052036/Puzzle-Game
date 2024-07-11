#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "getkey.h"

#if defined(_WIN32) || defined(_WIN64)

    #include <windows.h>
    void waitForKeyRelease(int virtualKey) 
    {
        while (GetAsyncKeyState(virtualKey) & 0x8000) {}           // wait until key release     
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   // avoid showing pressed key during process.
    }

    void get_key_window(char *direction) 
    {
        while (1) 
        {
            if (GetAsyncKeyState(VK_UP) & 0x8000) 
            {
                waitForKeyRelease(VK_UP);
                *direction = 'w';
                break;
            } 
            else if (GetAsyncKeyState('W') & 0x8000) 
            {
                waitForKeyRelease('W');
                *direction = 'w';
                break;
            } 
            else if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
            {
                waitForKeyRelease(VK_DOWN);
                *direction = 's';
                break;
            } 
            else if (GetAsyncKeyState('S') & 0x8000) 
            {
                waitForKeyRelease('S');
                *direction = 's';
                break;
            } 
            else if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
            {
                waitForKeyRelease(VK_LEFT);
                *direction = 'a';
                break;
            }
            else if (GetAsyncKeyState('A') & 0x8000) 
            {
                waitForKeyRelease('A');
                *direction = 'a';
                break;
            }  
            else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
            {
                waitForKeyRelease(VK_RIGHT);
                *direction = 'd';
                break;
            } 
            else if (GetAsyncKeyState('D') & 0x8000) 
            {
                waitForKeyRelease('D');
                *direction = 'd';
                break;
            }
            sleep(20);
        }
    }

#else
    #include <ctype.h>
    #include<termios.h>
    static struct termios orig_termios;         

    void set_noncanonical_mode()
    {
        struct termios term;
        tcgetattr(STDIN_FILENO, &orig_termios);         // Save the original terminal settings

        tcgetattr(STDIN_FILENO, &term);
        term.c_lflag &= ~(ICANON |ECHO);
        tcsetattr(STDIN_FILENO,TCSANOW,&term);
    }

    void set_canonical_mode()
    {
        // Restore the original terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW,&orig_termios);
    }   

    void get_key(char *direction)
    {

        char input=getchar();

        // Get key pressed.
        if (toupper(input) == 'A'||toupper(input) == 'S'||toupper(input) == 'D'||toupper((input)) == 'W')
            *direction = input;

        // Arrow keys are converted into ^[[A, ^[[B, ^[[C, ^[[D on linux. ^[ = Esc == 27 == '\033'
        // and '^[' is a single charecter just like null charcetr '\0'
        else if (toupper(input) == 27 && toupper(getchar()) == '[')    
        {
            switch(toupper(getchar()))
            {
                case 'A': *direction = 'w'; break;
                case 'B': *direction = 's'; break;
                case 'C': *direction = 'd'; break;
                case 'D': *direction = 'a'; break;
                default:  *direction = 'e'; break;   // no asdw no arrow key pressed.
            }
        }
    }
#endif


void get_key_pressed(char *direction)
{
    #if defined(_WIN32) || defined(_WIN64)
        get_key_window(direction);
    #else
        set_noncanonical_mode();
        get_key(direction);
        set_canonical_mode();
    #endif
}


void clear_input_buffer() 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}  //EOF-> END OF FILE
}
void clear_terminal(void)
{
    system(CLEAR);
}