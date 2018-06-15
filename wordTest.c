#include <stdio.h>
#include <stdlib.h>
#include "words.h"
int main() {
    char * filename = "testWords";
    FILE  * testWords = fopen(filename, "r");

    for (int i = 0; i < 20; i++) {
        char * word1 = getWord(testWords);
        if (word1 == 0) return 1;
        printf("%dth word: %s\n", i, word1);
    }

    return 0;
}
