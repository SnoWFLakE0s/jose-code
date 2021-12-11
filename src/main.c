/*
 * main.c
 */
#include "main.h"

int main(void){
    printf("Welcome to %s!\n",APP_NAME);


    FILE *op;
    op = fopen("Output.txt", "w");



    //need to add custom file name support

    FILE *fp; //file pointer
    char input[80]; //input array 80 chars long

    fp = fopen("input.josecode","r"); //opens input.josecode to be read
    if(fp == NULL) { //makes sure the file can be read
        perror("Error opening file");
        return(-1);
    }

    while (!feof(fp)) { //reads the file to check there's no EOF
        if( fgets (input, 80, fp)!=NULL ) {
            int c;
            const char *s = " "; //token key is a whitespace
            char *token;

            token = strtok(input, s); //strtok function

            /* walk through other tokens */
            while( token != NULL ) {
//                printf( " %s\n", token );
                fprintf(op," %s\n", token);

                token = strtok(NULL, s);
            }
        }
    }
    fclose(op); 
    return(SUCCESS);
}
