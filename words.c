#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int inAlphabet(char c) {
    return (c == 'a' ||
            c == 'b' ||
            c == 'c' ||
            c == 'd' ||
            c == 'e' ||
            c == 'f' ||
            c == 'g' ||
            c == 'h' ||
            c == 'i' ||
            c == 'j' ||
            c == 'k' ||
            c == 'l' ||
            c == 'm' ||
            c == 'n' ||
            c == 'o' ||
            c == 'p' ||
            c == 'q' ||
            c == 'r' ||
            c == 's' ||
            c == 't' ||
            c == 'u' ||
            c == 'v' ||
            c == 'w' ||
            c == 'x' ||
            c == 'y' ||
            c == 'z' ||
            // Upper case
            c == 'A' ||
            c == 'B' ||
            c == 'C' ||
            c == 'D' ||
            c == 'E' ||
            c == 'F' ||
            c == 'G' ||
            c == 'H' ||
            c == 'I' ||
            c == 'J' ||
            c == 'K' ||
            c == 'L' ||
            c == 'M' ||
            c == 'N' ||
            c == 'O' ||
            c == 'P' ||
            c == 'Q' ||
            c == 'R' ||
            c == 'S' ||
            c == 'T' ||
            c == 'U' ||
            c == 'V' ||
            c == 'W' ||
            c == 'X' ||
            c == 'Y' ||
            c == 'Z'); 
}

char * getWord(FILE * file) {
    int len = 0;
    char word[50];
    char * rtrn = 0;
    char * cursor;
    char c;

    if ((c = getc(file)) != EOF) {
        //Leading white space
        while (!inAlphabet(c))
            c = getc(file);

        do {
            word[len++] = c;
            if (len < 49) 
                c = getc(file);
        } while (inAlphabet(c));

        word[len] = (char) 0;
        rtrn = (char *) calloc(len, sizeof(char));
        stpcpy(rtrn, word);
    }
    return rtrn;
}




