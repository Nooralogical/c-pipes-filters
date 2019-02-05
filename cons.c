#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//removes consecutive white spaces, replaces with one space
int filter(FILE *input, FILE *output) {

    while (!feof(input)) {
        if (ferror(input)) {
            return 1;
        }
        int ch;
        int lastCh;
        
        while ((ch = fgetc(input)) != EOF) {
            if (ch == ' ') {
                if (lastCh == ' ') {
                    break;
                }
            }
            lastCh = ch;
            fputc(ch, output);
        }
    }
    return 0;
}

int main(void) {
    const int retval = filter(stdin, stdout);
    fflush(stdout);
    return retval;
}