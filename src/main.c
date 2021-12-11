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
                fprintf(op,"%s\n", token);

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

    char boat[] = "int\n";
    printf("this is the boat:%s, the length is %d\n", boat, strlen(boat));

    char *line = NULL;
    size_t len = 0;

    int line_num = 1;
    while(getline(&line, &len, op) != -1) {
        line_num++;
        if((strcmp(boat , line)) == 0) {
            printf("success at line %d!\n", line_num);
            printf("line:%d,strcmp value:%d,str:%s,strlen:%d\n",line_num, strcmp(line , boat),line, strlen(line));
        }
    }
    fclose(op);
    fclose(fp);
    fclose(cp);
    free(line);

    return(SUCCESS);
}
