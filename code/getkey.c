#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char get_key_window(void);
char get_key(void);

char get_key_pressed(void)
{
    #if defined(_WIN32) || defined(_WIN64)
        return get_key_window();
    #else
        return get_key();
    #endif
}

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

char get_key()
{
    // code for no window OS
}