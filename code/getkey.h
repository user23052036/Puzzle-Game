#ifndef GETKEY_H
#define GETKEY_H


#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "cls"
    void waitForKeyRelease(int);
    void get_key_window(char*);

#else
    #define CLEAR "clear"
    void set_noncanonical_mode();
    void get_key(char*);
    void set_canonical_mode();
#endif


// Function to get the key pressed.
void get_key_pressed(char *direction);

void clear_input_buffer();
void clear_terminal(void);


#endif