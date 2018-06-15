/*************************************************************
    Finite Automata Launguage (FAL)
    A language designed around the concept of 
    Finite State Machines.

    Author: Andrew Thorp
    Version: 2018.06.14
**************************************************************/

#include <stdio.h>
#include "states.h"


/*
    Main takes in a filepath as input, parses the file, and passes the
    resulting to a splitter. It then takes the results of the splitter,
    and passes the strings off to the FSM builder and the code handler
    respectively.
*/
int main(int argc, char * argv[]) {

    State * states;
    while ( --argc > 0 ) {
        FILE * program = fopen(*++argv, "r");
        states = buildStates(program);
    }
}

