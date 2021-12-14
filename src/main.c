/* * main.c
 */
#include "main.h"

int main(void){
    printf("Welcome to %s!\n",APP_NAME);

    //need to add function to wipe any output.c s
    //need to add custom file name support

    FILE *fp; //file pointer to input file
    fp = fopen("../output/input.josecode","r"); //opens input.josecode to be read
    if(fp == NULL) { //makes sure the file can be read
        perror("Error opening input file");
        return(-1);
    }
    FILE *op; //file pointer to output text file
    op = fopen("../output/output.txt", "w"); //opens output.txt to be wrote to
    if(op == NULL) { //makes sure the file can be read
        perror("Error opening output text file");
        return(-1);
    }

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
    fclose(op); 
    printf("intermediary file successfully created\n");

    FILE *cp; //file pointer to output c file
    cp = fopen("../output/output.c","w"); //opens the output.c file for writing 
    if(cp == NULL) { //makes sure the file can be read
        perror("Error opening output c file");
        return(-1);
    }
    op = fopen("../output/output.txt", "r"); //opens output.txt to be read
    if(op == NULL) { //makes sure the file can be read
        perror("Error opening output text file");
        return(-1);
    }

    char *output_start[] = {
        "#include \"josecode.h\"",
        "\n",
        "int main(void) {",
        ""
    }, **i;
    i = output_start;
    char *output_end[] = {
        "return 0;\n",
        "}",
        ""
    }, **j;
    j = output_end;

    while(*i != "") {
        fprintf(cp, "%s\n", *i++);
    }

    char *line = NULL;
    size_t len = 0;
    char space[] = " ";
    char endpar[] = ");\n";
    //int line_num = 1;
    while(getline(&line, &len, op) != -1) {
        if(strcmp("(\n", line) == 0) { //if an open parenthese is detected
            char str_temp[80] = "( "; //create temporary string
            while(strcmp(line, ");\n") != 0) { //until close parenthese is detected
                //printf("input line =%s", line);
                getline(&line, &len, op); //get a new line
                strcat( str_temp, line); //concatenate to previous line
                //printf("temp str=%s", str_temp); //test print - will remove later
            }
            for(int i = 0;i < 80; i++) {
                if(str_temp[i] == '\n') {
                    str_temp[i] = ' ';
                }
            }
            fprintf(cp, "%s", str_temp); //test print - will remove later
        }
        if(strcmp(");\n", line) == 0) {
            getline(&line, &len, op);
        }
        if(strcmp(josecode[0], line) == 0) {
            fprintf(cp, "%s", native[0]);        
        } else if(strcmp(josecode[1], line) == 0) {
            fprintf(cp, "%s", native[1]);
        } else {
            fprintf(cp, "%s", line);
        } 
    }

    while(*j != "") {
        fprintf(cp, "%s\n", *j++);
    }

    fclose(op);
    fclose(fp);
    fclose(cp);
    free(line);
    printf("Finished Compiling josecode\n");
    
    system("cd ../output && make run");
    return(SUCCESS);
}
