/*
 * project.c
 */
#include "project.h"

/*
 * Global Variable definitions, if needed.
 */
char *josecode[15] = {
    "loggers\n",
    "power\n",
    "tellme\n",
    "giveme\n",
    "jazzup\n",
};

char *native[] = {
    "log",
    "pow",
    "printf",
    "scanf",
    "rand",
    
};
/*
 * Data Structure definitions, if needed.
 */

/*
 * Function declarations, if needed.
 */
int dontCareAboutValue(float a) {
    a = (int)a;
    return a;
}

int bigger(int a, int b) {
    if(a>b) {
        return a;
    }
    else if(a<b) {
        return b;
    } //what do we do if they're equal?
}

int smaller(int a, int b) {
    if(a>b) {
        return b;
    }
    else if(a<b) {
        return a;
    } //what do we do if they're equal?
}

