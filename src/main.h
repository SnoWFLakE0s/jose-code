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
/*
 * Global Variable declarations, if needed.
 */

/*
 * Data Structure declarations, if needed.
 */

/*
 * Function declarations, if needed.
 */

#endif /* MAIN_H */
