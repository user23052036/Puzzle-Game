#include <stdio.h>
#include <unistd.h>
#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>

    char get_key_window(void)
    {
        while (1) {

            // 0x8000 compare the 15 bits. If it's 1, the key is pressed.
            if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState('W') & 0x8000) {
                Sleep(50);
                return 'w'; // Evita múltiples detecciones
            }
            if (GetAsyncKeyState(VK_DOWN) & 0x8000 || GetAsyncKeyState('S') & 0x8000) {
                Sleep(50);
                return 's';
            }
            if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState('A') & 0x8000) {
                Sleep(50);
                return 'a';
            }
            if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState('D') & 0x8000) {
                Sleep(50);
                return 'd';
            }

            Sleep(50); // Para no sobrecargar la CPU
        }
    }

#else
#include <ctype.h>
char get_key(void)
{
    char key_pressed[5];
    scanf("%s",key_pressed);

    // Get key pressed.
    if (toupper(key_pressed[0]) == 'A' || toupper(key_pressed[0]) == 'S' || 
    toupper(key_pressed[0]) == 'D' || toupper(key_pressed[0]) == 'W')
    return key_pressed[0];
    // Arrow keys are converted into ^[[A, [[B, [[C, [[C on linux. ^[ = Esc.
    else if (toupper(key_pressed[0]) == 27 && toupper(key_pressed[1]) == '[')     // 27 = Esc
    {
        if (toupper(key_pressed[2]) == 'A')
            return 'w';
        else if (toupper(key_pressed[2]) == 'B')
            return 's';
        else if (toupper(key_pressed[2]) == 'C')
            return 'd';
        else if (toupper(key_pressed[2]) == 'D')
            return 'a';
    }
}
#endif


char get_key_pressed(void)
{
    #if defined(_WIN32) || defined(_WIN64)
        return get_key_window();
    #else
        return get_key();
    #endif
}