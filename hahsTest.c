#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

int main() {

    char string0[] = "foo";
    char string1[] = "foo";
    char string2[] = "bar";

    State state0 = (State) malloc(sizeof(*state0));
    strcpy(state0->name, string0);
    printf("String0: %s, Hash: %d\n", string0, hash(state0));

    State state2 = (State) malloc(sizeof(*state2));
    strcpy(state2->name, string2);
    printf("String2: %s, Hash: %d\n", string2, hash(state2));

    State state1 = (State) malloc(sizeof(*state1));
    strcpy(state1->name, string1);
    printf("String1: %s, Hash: %d\n", string1, hash(state1));


}
