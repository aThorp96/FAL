#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

int main() {

    char string0[] = "foo";
    char string1[] = "foo";
    char string2[] = "bar";
    State transitions[52];

    State state0 = newState(0, string0, transitions);
    printf("String0: %s, Hash: %d\n", string0, hash(state0));

    State state2 = (State) malloc(sizeof(*state2));
    strcpy(state2->name, string2);
    printf("String2: %s, Hash: %d\n", string2, hash(state2));

    State state1 = (State) malloc(sizeof(*state1));
    strcpy(state1->name, string1);
    printf("String1: %s, Hash: %d\n", string1, hash(state1));

    State * table = newHashTable();
    insert(table, state0);
    insert(table, state2);
    printf("State2 type: %d\n", find(table, string2)->type);
    printf("State1: %s\n", delete(table, string0)->name);


}
