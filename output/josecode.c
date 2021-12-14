#include "josecode.h"

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
    } else {
        return a;
    }
}

int smaller(int a, int b) {
    if(a>b) {
        return b;
    }
    else if(a<b) {
        return a;
    } else {
        return a;
    }
}

