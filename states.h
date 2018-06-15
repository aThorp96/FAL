#ifndef states_h_INCLUDED
#define states_h_INCLUDED
//  Transition is a map of character input to a string statename.
typedef struct _transition * Transition;
typedef struct _state * State;

struct _transition;

/* 
    States have an array of 52 transitions; one for every character in the 
    English alphabet (upper and lower case are distinguished)
*/
struct _state;
State * buildStates(FILE * program);

#endif // states_h_INCLUDED

