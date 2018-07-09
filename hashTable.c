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
        //printf("Hashbuilder- hash = %d: cursor = %c (%d)\n", hash, *string, (int) *string);
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

State delete(State table[], char * name) {
    int index = hashValue(name);
    if(table[index] != 0x0){
        State selected = table[index];
        table[index] = 0;
        return selected;
    } else {
        //State already deleted.
        return 0x0;
    }
}

State find(State table[], char * name) {
    int index = hashValue(name);
    if(table[index] != 0x0){
        return table[index];
    } else {
        printf("Error: State %s not in table\n", name);
        return 0;
    }
}


