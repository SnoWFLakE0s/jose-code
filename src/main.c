/*
 * main.c
 */
#include "main.h"

int main(void){
    printf("Welcome to %s!\n",APP_NAME);

    //need to add custom file name support

    FILE *fp; //file pointer to input file
    fp = fopen("input.josecode","r"); //opens input.josecode to be read
    FILE *op; //file pointer to output text file
    op = fopen("output.txt", "w"); //opens output.txt to be wrote to

    if(fp == NULL) { //makes sure the file can be read
        perror("Error opening input file");
        return(-1);
    }

    char input[80]; //input array 80 chars long
    while (!feof(fp)) { //reads the file to check there's no EOF
        if( fgets (input, 80, fp)!=NULL ) {
            int c;
            const char *s = " "; //token key is a whitespace
            char *token;

            token = strtok(input, s); //strtok function

            /* walk through other tokens */
            while( token != NULL ) {
                fprintf(op," %s\n", token);

                token = strtok(NULL, s);
            }
        }
    }
    fclose(op); 

    FILE *cp; //file pointer to output c file
    cp = fopen("output.c","w"); //opens the output.c file for writing 
    op = fopen("output.txt", "r"); //opens output.txt to be read
    if(op == NULL) { //makes sure the file can be read
        perror("Error opening output file");
        return(-1);
    }


    char boat[] = "each";
    char boat2[] = "boat";


    /*
    while (!feof(op)) { //reads the file to check there's no EOF
        if( fgets (input, 80, op)!=NULL ) {
            int c;
            const char *s = " "; //token key is a whitespace
            char *token;

            token = strtok(input, s); //strtok function
            //walk through other tokens 
            while( token != NULL ) {
                if((strcmp((fgets (input, 80, op)),boat)) == 0) {
//                    fprintf(cp," %s\n", boat2);
                      printf("success!");
                    } 
                token = strtok(NULL, s);
            }
        }
    }
     
*/

    char *line = NULL;
    size_t len = 0;

    /*getline(&line, &len, op);
    printf("the getline value is : %d\n", getline(&line, &len, op));

    printf("This is the line :%s\n", line); 
    printf("this is the boat:%s\n", boat);
    */ 
    while(getline(&line, &len, op) != -1) {
        if((strcmp(line , boat)) == 0) {
            printf("success!");
        }
    }
    fclose(op);
    fclose(fp);
    fclose(cp);
    free(line);

    return(SUCCESS);
}
