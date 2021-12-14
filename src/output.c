#include <stdio.h>
#include <math.h>


int main(void) {
double
value_1;

double
value_2;

double
result;

value_1
=
2.0;

value_2
=
8.0;



result
=
log( value_1 ); 
printf
( "Loggers of %f is %f\n", value_1 , result ); 


result
=
pow( value_1 , value_2 ); 
printf
( "Power of %f to the %f is %f\n", value_1 , value_2 , result ); 




return 0;

}
