#ifndef states_h_INCLUDED
#define states_h_INCLUDED
#include <stdio.h>
//  Transition is a map of character input to a string statename.
typedef struct _state {

    int type;
    char name[50];
    struct _state * transitions[52];
} * State;

State newState(int type, char * name, State transitions[52]);


/* 
    States have an array of 52 transitions; one for every character in the 
    English alphabet (upper and lower case are distinguished)
*/
State * buildStates(FILE * program);

#endif // states_h_INCLUDED

