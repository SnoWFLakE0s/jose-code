#ifndef JOSECODE_H
#define JOSECODE_H

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#define SUCCESS 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int dontCareAboutValue();
int bigger();
int smaller();

#endif /* MAIN_H */














