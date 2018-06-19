#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int inAlphabet(char c) {
    switch (c) {
        case 'a' :
        case 'b' :
        case 'c' :
        case 'd' :
        case 'e' :
        case 'f' :
        case 'g' :
        case 'h' :
        case 'i' :
        case 'j' :
        case 'k' :
        case 'l' :
        case 'm' :
        case 'n' :
        case 'o' :
        case 'p' :
        case 'q' :
        case 'r' :
        case 's' :
        case 't' :
        case 'u' :
        case 'v' :
        case 'w' :
        case 'x' :
        case 'y' :
        case 'z' :
        // Upper case
        case 'A' :
        case 'B' :
        case 'C' :
        case 'D' :
        case 'E' :
        case 'F' :
        case 'G' :
        case 'H' :
        case 'I' :
        case 'J' :
        case 'K' :
        case 'L' :
        case 'M' :
        case 'N' :
        case 'O' :
        case 'P' :
        case 'Q' :
        case 'R' :
        case 'S' :
        case 'T' :
        case 'U' :
        case 'V' :
        case 'W' :
        case 'X' :
        case 'Y' :
        case 'Z' :
            return 1;
        default:
            return 0;
    }
}

int whiteSpace(char c) {
    switch (c) {
        case '\n':
        case '\t':
        case ' ' :
            return 1;
        default:
            return 0;
    }
}

char * getWord(FILE * file) {
    int len = 0;
    char word[50];
    char * rtrn = 0;
    char c;

    if ((c = getc(file)) != EOF) {
        //Leading white space
        while (!inAlphabet(c))
            c = getc(file);

        do {
            if (len < 49) {
                word[len++] = c;
            }
        } while ((c = getc(file)) != EOF && inAlphabet(c));

        word[len] = (char) 0;
        rtrn = (char *) calloc(len, sizeof(char));
        stpcpy(rtrn, word);
    }
    return rtrn;
}

char * getUntilChar(FILE * file, char endChar) {
    int len = 0;
    char word[50];
    char * rtrn = 0;
    char c;

    while ((c = getc(file) !=  EOF && c != endChar && inAlphabet(c)) {
        word[len++] = c;
    }
    if (c == endChar) {
        word[len] = (char) 0;
        rtrn = (char *) calloc(len, sizeof(char));
        stpcpy(rtrn, word);
    }
    return rtrn;
}

void skipWhiteSpace(FILE * file) {
    char c;
    while ((c = getc(file)) != EOF && whiteSpace(c));
    unget(c, file);
}



