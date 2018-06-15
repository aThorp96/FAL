#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * getWord(FILE * file) {
    int len = 0;
    char word[50];
    char * rtrn = 0;
    char * cursor;
    char c;

    if ((c = getc(file)) != EOF) {
        //Leading white space
        while (c == ' ' || c == '\t' || c == '\n')
            c = getc(file);

        do {
            word[len++] = c;
            c = getc(file);
        } while (c != ' ' && c != '\t' && c != '\n' && len < 49);

        word[len] = (char) 0;
        rtrn = (char *) calloc(len, sizeof(char));
        stpcpy(rtrn, word);
    }
    return rtrn;
}

