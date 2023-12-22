#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {

float *num1 = (float *) malloc (sizeof(float));
float *num2 = (float *) malloc (sizeof(float));
float *num3 = (float *) malloc (sizeof(float));
char *op = (char *) malloc (1);

scanf("%f %c %f", num1, op, num2);

if (*op == *"+") {
*num3 = *num1 + *num2;
}

if (*op == *"-") {
*num3 = *num1 - *num2;
}

if (*op == *"/" || *op == *":") {
*num3 = *num1 / *num2;
}

if (*op == *"x" || *op == *"*") {
*num3 = *num1 * *num2;
}

printf("%.3f", *num3);
printf("\n");

free(num1);
free(num2);
free(num3);
free(op);
return 0;
}
