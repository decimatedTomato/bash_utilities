/*
I want to be able to add things into my clipboard like this
> echo "aaa" | clip
Using the windows api
*/

#include <windows.h>
#include <string.h>
#include <stdio.h>

#define MAX_LEN 1028

int main(int argc, char **argv) {
    char input[MAX_LEN] = { 0 };
    if (argc == 1) {
        // Read input through pipe
        if (!fgets(input, MAX_LEN, stdin)) return EXIT_FAILURE;
    } else {
        // Read input through command line argument
        size_t total_len = 0;
        for (int arg = 1; arg < argc; arg++) {
            total_len += strlen(argv[arg]) + 1;
        }
        char *cl_args = malloc(total_len);
        char *current = cl_args;
        for (int arg = 1; arg < argc; arg++) {
            strcpy(current, argv[arg]);
            current += strlen(argv[arg]);
            *current++ = (arg == argc) ? '\0' : ' ';
        }
        
        // Copy into input buffer
        strncpy(input, cl_args, total_len);
        input[MAX_LEN-1] = '\0'; 
        free(cl_args);
    }
    const size_t len = strlen(input) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), input, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    return EXIT_SUCCESS;
}