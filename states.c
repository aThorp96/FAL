#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"
#include "hashTable.h"

#define asciiOffest 101
 
/* 
    States have an array of 52 transitions; one for every character in the 
    English alphabet (upper and lower case are distinguished)
typedef struct _state {
    int type;
    char name[50];
    struct _state * transitions[52];
} * State;
*/

State newState(int type, char * name, State transitions[52]) {
    State s = (State) malloc(sizeof(s));

    s->type = type;
    strcpy(s->name,name);
    for (int i = 0; i < 52; i++) {
        s->transitions[i] = transitions[i];
    }

    return s;
}

void printState(State state) {
    char * type = "";

    switch (state->type) {
        case 1:
            type = "Start";
            break;
        case 2:
            type = "Accept";
            break;
        default:
            break;
    }

    printf("%sState %s\n", type, state->name);
    printf("Transitions:\n");
    for (int i = 0; i < 62; i++){
        printf("%c\t%s", i + asciiOffest, state->transitions[i]->name);
    }
}


/*
    buildStates take in a file and builds the graph represented in
    that file. Every file must have one start state and at least one goal state.

    precondition: buildStates assumes the given file has already been opened by 
        or before the calling function. 
*/
State buildState(FILE * inFile, State stateTable[]) {


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
    char * word;
    int type = 0;
    char * name;
    char c;
    State transitions[62];

    while(componant < 8) {
        switch (componant) {
            case 0: //State Type
                word = getWord(inFile);
                if (strcmp(word, "start")) {
                    type = 1;
                    componant = 1;
                }
                else if (strcmp(word, "accept")) {
                    type = 2;
                    componant = 1;
                }
                else if (strcmp(word, "state")) {
                    componant = 1;
                }
                else {
                    ;
                }
                    //handle error
                break;
            case 1: //State Name
                word = getWord(inFile);
                name = word;
                componant = 2;
                break;
            case 2: // Open Brace
                c = getc(inFile);
                if (c != '{') {
                    //handle error
                }
                else {
                    skipWhiteSpace(inFile);
                    componant = 3;
                }
                break;
            case 3: //Transition Character
                c = getc(inFile);
                componant = 4;
                break;
            case 4: //Colon
                if (getc(inFile) == ':') {
                    componant = 5;
                } else {
                    //error
                }
                break;
            case 5: //State Name
                word = getWord(inFile);
                componant = 6;
                break;
            case 6: //Semicolon
                if (getc(inFile) == ';') {
                    transitions[(int) c - asciiOffest] = find(stateTable, word);
                } else {
                    // error
                }
                componant = 7;
                break;
            case 7: //Close  Brace
                skipWhiteSpace(inFile);
                // if Not close brace componant goes back to 7;
                if ((c = getc(inFile)) == '}') {
                    componant = 8;
                } else {
                    componant = 6;
                    ungetc(c, inFile);
                }
                break;
            default:
                break;
        }
    }
    State state = newState(type, name, transitions);
    printState(state);
    return state;
}

