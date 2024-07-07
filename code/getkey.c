#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "cls"
    #include <windows.h>
    

    void waitForKeyRelease(int virtualKey) {
        while (GetAsyncKeyState(virtualKey) & 0x8000) {}   // wait until key release     
        FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));   // avoid showing pressed key during process.
    }

    void get_key_window(char *direction) {
        while (1) {
            if (GetAsyncKeyState(VK_UP) & 0x8000) {
                waitForKeyRelease(VK_UP);
                *direction = 'w';
                break;
            } else if (GetAsyncKeyState('W') & 0x8000) {
                waitForKeyRelease('W');
                *direction = 'w';
                break;
            } else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                waitForKeyRelease(VK_DOWN);
                *direction = 's';
                break;
            } else if (GetAsyncKeyState('S') & 0x8000) {
                waitForKeyRelease('S');
                *direction = 's';
                break;
            } else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                waitForKeyRelease(VK_LEFT);
                *direction = 'a';
                break;
            } else if (GetAsyncKeyState('A') & 0x8000) {
                waitForKeyRelease('A');
                *direction = 'a';
                break;
            } else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                waitForKeyRelease(VK_RIGHT);
                *direction = 'd';
                break;
            } else if (GetAsyncKeyState('D') & 0x8000) {
                waitForKeyRelease('D');
                *direction = 'd';
                break;
            }
        }
    }

#else
    #define CLEAR "clear"
    #include <ctype.h>

    void clear_input_buffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }

    void get_key(char *direction)
    {
        char key_pressed[5];
        
        do
        {
            for (int i = 0; i < 5; i++)
                    key_pressed[i] = '\0';
            
            scanf("%4s",key_pressed);
            clear_input_buffer();

            // Get key pressed.
            if (toupper(key_pressed[0]) == 'A' || toupper(key_pressed[0]) == 'S' || 
            toupper(key_pressed[0]) == 'D' || toupper(key_pressed[0]) == 'W')
            *direction = key_pressed[0];
            // Arrow keys are converted into ^[[A, [[B, [[C, [[C on linux. ^[ = Esc.
            else if (toupper(key_pressed[0]) == 27 && toupper(key_pressed[1]) == '[')     // 27 = Esc
            {
                switch(toupper(key_pressed[2]))
                {
                    case 'A': *direction = 'w'; break;
                    case 'B': *direction = 's'; break;
                    case 'C': *direction = 'd'; break;
                    case 'D': *direction = 'a'; break;
                    default: *direction = 'e'; break;   // no asdw no arrow key pressed.
                }
            }
            else
                *direction = 'e';
                
        } while (*direction == 'e');
    }
#endif


void get_key_pressed(char *direction)
{
    #if defined(_WIN32) || defined(_WIN64)
        get_key_window(direction);
    #else
        get_key(direction);
    #endif
}

void clear_terminal(void){
    system(CLEAR);
}