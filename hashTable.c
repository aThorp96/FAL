#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "states.h"

#define size 1000

unsigned hash(State state) {
    char * cursor = &state->name[0];
    int hash;
    for (hash = 0; * cursor != '\0'; cursor++) {
        printf("Hashbuilder- hash = %d: cursor = %c (%d)\n", hash, *cursor, (int) *cursor);
        hash = * cursor + 31 * hash;
    }
    return hash % (unsigned) size;
}

void insert(State table[], State state) {

    int index = hash(state);
    if(table[index] == 0x0){
        table[index] = state;
    } else {
        // handle collision
    }
}

State delete(State table[], State * state) {

}

State find(State table[], State * state) {

}


