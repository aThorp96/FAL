#include <stdio.h>
#include "words.h"
 
//  Transition is a map of character input to a string statename.
typedef struct _transition * Transition;
typedef struct _state * State;

struct _transition {
    char input;
    char * state;
};


/* 
    States have an array of 52 transitions; one for every character in the 
    English alphabet (upper and lower case are distinguished)
*/
struct _state {

    char name[50];
    Transition transitions[52];

};

State * buildStates(FILE * program) {

}

