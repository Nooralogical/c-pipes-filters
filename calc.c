#include <stdio.h>

//calculates the number of chars, white spaces, words and lines
int filter(FILE *input, FILE *output) {
    
    while (!feof(input)) {
        if (ferror(input)) {
            return 1;
        }

        int countChars = 0;
        int countWhite = 0;
        int countWords = 0;
        int countLines = 0;
        int lastCh;
        int ch;

        while ((ch = fgetc(input)) != EOF) {
            if (ch != ' ' && ch != '\n') { 
                ++countChars; 
            }
            if (ch == ' ' || ch == '\n') {
                //check that the previous character was a letter, not whitespace etc.
                if (lastCh != ' ' && lastCh != '\n') {
                    //if so = word
                    ++countWords;
                }
            }
            if (ch == '\n') { 
               ++countLines;
            }
            if (ch == ' ') {
                ++countWhite;
            }
            lastCh = ch;
	   }
       if (countChars > 0) {
		++countLines;
        ++countWords;
	   }
        printf("Chars: %d\n", countChars);
        printf("Whitespace: %d\n", countWhite);
        printf("Lines: %d\n", countLines);
        printf("Words: %d\n", countWords);
    }
    return 0;
}

int main(void) {
    const int retval = filter(stdin, stdout);
    fflush(stdout);
    return retval;
}