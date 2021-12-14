/*
 * main.h
 */
#ifndef MAIN_H
#define MAIN_H

#define APP_NAME "josecode"

#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#define SUCCESS 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
/*
 * Global Variable declarations, if needed.
 */

/*
 * Data Structure declarations, if needed.
 */

/*
 * Function declarations, if needed.
 */
char loggers[] = "loggers( \n";
char swaploggers[] = "log";
char power[] = "power(\n";
char swappower[] = "pow(";
char dontcare[] = "dontCareAboutValue(\n";
char swapdontcare[] = "round(";
extern char *josecode[15];
extern char *native[15];
#endif /* MAIN_H */














