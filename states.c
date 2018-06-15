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

/*
    buildStates take in a file and builds the graph represented in
    that file. Every file must have one start state and at least one goal state.

    precondition: buildStates assumes the given file has already been opened by 
        or before the calling function. 
*/
State * buildStates(FILE * program) {

    char * currentWord;


}

