#ifndef words_h_INCLUDED
#define words_h_INCLUDED

int inAlphabet(char c);

int whiteSpace(char c);

void skipWhiteSpace(FILE * file);

char * getWord(FILE * file);

char * getUntilChar(FILE * file, char endChar);

#endif // words_h_INCLUDED

