#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "states.h"

#define size 1000

State * newHashTable() {
    State * table=  malloc(size * sizeof(State));
    return table;
}

unsigned hashValue(char * string) {
    int hash;
    for (hash = 0; * string != '\0'; string++) {
        printf("Hashbuilder- hash = %d: cursor = %c (%d)\n", hash, *string, (int) *string);
        hash = * string + 31 * hash;
    }
    return hash % (unsigned) size;
}

unsigned hash(State state) {
    char * name = &state->name[0];
    return hashValue(name);

}

void insert(State table[], State state) {

    int index = hash(state);
    if(table[index] == 0x0){
        table[index] = state;
    } else {
        // handle collision
    }
}

State delete(State table[], State state) {

}

State find(State table[], char * name) {
    int index = hashValue(name);
    if(table[index] != 0x0){
        return table[index];
    } else {
        return 0;
    }
}


