#ifndef hashTable_h_INCLUDED
#define hashTable_h_INCLUDED
#include "states.h"
int hash(State state);

void insert(State table[], State state);

State delete(State table[], State * state);

State find(State table[], State * state) ;
#endif // hashTable_h_INCLUDED

