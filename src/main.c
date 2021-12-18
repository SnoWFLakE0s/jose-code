/* * main.c
 */
#include "main.h"

int main(void){
    //Josh
    char fileName[80]; //makes array to write User's filename to
    char inputName[80] = "../input/"; //array for concatenation
    printf("\nWelcome to the %s compiler!\n",APP_NAME);
    printf("Please enter the name of your josecode program in the input directory, including the file extension: ");
    scanf("%s",&fileName[0]);
    strcat(inputName,fileName); //concatenates User's file name to the directory

    //Matt
    FILE *fp; //file pointer to input file
    fp = fopen(inputName,"r"); //opens input josecode file to be read
    if(fp == NULL) { //makes sure the file can be read
        perror("Error opening input josecode file. Me no likey!");
        return(-1);
    }
    FILE *op; //file pointer to output text file
    op = fopen("../output/output.txt", "w"); //opens output.txt to be wrote to
    if(op == NULL) { //makes sure the file can be read
        perror("Error opening the temporary file. Me no likey!");
        return(-1);
    }

    //Matt
    char input[80]; //input array 80 chars long
    while (!feof(fp)) { //reads the file to check there's no EOF
        if( fgets (input, 80, fp)!=NULL ) {
            int c;
            const char *s = " "; //token key is a whitespace
            char *token;

            token = strtok(input, s); //strtok function

            // walk through other tokens 
            while( token != NULL ) {
                fprintf(op,"%s\n", token);
                token = strtok(NULL, s);
            }
        }
    }
    fclose(op);// closes to then reopen to be read instead of written
    printf("\nLOG:\nIntermediary file successfully created.\nBeginning C conversion...\n");//success message

    //Matt
    FILE *cp; //file pointer to output c file
    cp = fopen("../output/output.c","w"); //opens the output.c file for writing 
    if(cp == NULL) { //makes sure the file can be read
        perror("Error opening output c file! Me no likey.");
        return(-1);
    }
    op = fopen("../output/output.txt", "r"); //opens output.txt to be read
    if(op == NULL) { //makes sure the file can be read
        perror("Error opening output text file! Me no likey.");
        return(-1);
    }

    //Josh
    char *output_start[] = {//start of an outline of an average C program
        "#include \"josecode.h\"",
        "\n",
        "int main(void) {",
        ""
    }, **i;
    i = output_start;
    char *output_end[] = {//end of an outline of an average C program
        "return 0;\n",
        "}",
        ""
    }, **j;
    j = output_end;
    while(*i != "") {//until the "" is detected
        fprintf(cp, "%s\n", *i++);//writes to start of file
    }

    //combination of Matt and Josh
    char *line = NULL;//setup for getline function
    size_t len = 0;
    while(getline(&line, &len, op) != -1) {//until eof is detected in getline function
        if(strcmp("(\n", line) == 0) { //if an open parenthese is detected
            char str_temp[80] = "( "; //create temporary string
            while(strcmp(line, ");\n") != 0) { //until close parenthese is detected
                getline(&line, &len, op); //get a new line
                strcat( str_temp, line); //concatenate to previous line
            }
            for(int i = 0;i < 80; i++) {//replaces any newlines with spaces
                if(str_temp[i] == '\n') {
                    str_temp[i] = ' ';
                }
            }
            fprintf(cp, "%s", str_temp); //once done it writes to the file
        }
        if(strcmp(");\n", line) == 0) {//skips writing extra ending parentheses
            getline(&line, &len, op);
        }
        //replaces josecode key words
        if(strcmp(josecode[0], line) == 0) {
            fprintf(cp, "%s", native[0]); 
        } else if(strcmp(josecode[1], line) == 0) {
            fprintf(cp, "%s", native[1]);
        } else if(strcmp(josecode[2], line) == 0) {
            fprintf(cp, "%s", native[2]);
        } else if(strcmp(josecode[3], line) == 0) {
            fprintf(cp, "%s", native[3]);
        } else {
            fprintf(cp, "%s", line);
        } 
    }

    //Josh
    while(*j != "") {//writes to end of file
        fprintf(cp, "%s\n", *j++);
    }
    //Closes all files and frees line for memory management.
    fclose(op);
    fclose(fp);
    fclose(cp);
    free(line);
    printf("Finished josecode compilation! Me likey. \nNow running program...\n\n");//success message
    
    //Matt
    system("cd ../output && make run");//Automatically builds and runs the output C file.
    printf("\n");
    return(SUCCESS);
}
