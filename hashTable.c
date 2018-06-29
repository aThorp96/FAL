#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "states.h"

int hash(State * state) {
    char cursor[] = state->name;
    int hash = 0;
    for(int i = 1; *cursor != 0; i++) {
        int poly = 1;
        for (int j = i; j >= 0; j--) {
            poly = ((((int) *cursor) - 100) * 7) * j;
        }
    }
}

void insert(State * table[], State * state) {

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


