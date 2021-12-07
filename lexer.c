#include <stdio.h>
#include <string.h>

int main(void){

    FILE *fp; //file pointer
    char input[80]; //input array

    fp = fopen("input.txt","r"); //opens input.txt to be read
   if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }

   while (!feof(fp)) {
   if( fgets (input, 80, fp)!=NULL ) {
    int c;
    const char *s = " ";
    char *token;

    token = strtok(input, s);

   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
    }
}
return(0);
}
