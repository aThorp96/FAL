#include <stdio.h>
#include <string.h>
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

    int stateType;
    char name[50];
    Transition transitions[52];

};

/*
    buildStates take in a file and builds the graph represented in
    that file. Every file must have one start state and at least one goal state.

    precondition: buildStates assumes the given file has already been opened by 
        or before the calling function. 
*/
State * buildStates(FILE * inFile) {

    char * word;

    //  Componant is the part of the state definition the parser 
    //  expects. 
    //  0:  State type
    //  1:  State name
    //  2:  Open Brace
    //  3:  transition character
    //  4:  Colon
    //  5:  State name (resulting state)
    //  6:  Semicolon
    //  7:  Close Brace
    int componant = 0;

    while((word = getWord(inFile)) != EOF) {

        int type = 0;
        char * name;
        Transition transitions;

        switch (componant) {
            case 0: //State Type
                word = getWord(file);
                if (strcmp(word, "start")
                    type = 1;
                    componant = 1;
                else if (strcmp(word, "accept"))
                    type = 2;
                    componant = 1;
                else if (strcmp(word, "state"))
                    componant = 1;
                else;
                    //handle error
                    break;
                  
            case 1: //State Name
                    word = getWord(file);
                    name = word;
                    componant = 2;
                    break;
            case 2: // Open Brace
                    char c = getc(file);
                    if (c != '{')
                        //handle error
                    else {
                        skipWhiteSpace(file);
                        componant = 3;
                    }
                    break;
            case 3: //Transition Character

            case 4: //Colon
            case 5: //State Name
            case 6: //Semicolon
            case 7: //Close  Brace
    }

}

