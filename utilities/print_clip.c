/*
Prints the contents of the clipboard using windows api
*/

#include <windows.h>
#include <stdio.h>

int main() {
    OpenClipboard(0);
    HANDLE hglb = GetClipboardData(CF_TEXT);
    // if (hglb == NULL) {
    if (hglb == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "%lu failed at getClipboardData", GetLastError());
        return EXIT_FAILURE;
    }
    char *data = (char*)GlobalLock(hglb);
    if (data == NULL) {
        fprintf(stderr, "%lu failed at GlobalLock", GetLastError());
        return EXIT_FAILURE;
    }
    printf("%s", data);
    GlobalUnlock(hglb);
    CloseClipboard();
    return EXIT_SUCCESS;
}