#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char * getWord(FILE * file) {
    int len = 0;
    char word[50];
    char * rtrn;
    char c;
    if ((c = getc(file)) != EOF) {
        //Leading white space
        while (c == ' ' || c == '\t' || c == '\n')
            c = getc(file);
        while (c != ' ' || c != '\t' || c != '\n') {
            c = getc(file);
            word[len++] = c;
        }
        rtrn = (char *) calloc(len, sizeof(char));
    }
    return rtrn;
}

