#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
float *num1 = (float *)malloc(sizeof(float));
float *num2 = (float *) malloc (sizeof(float));
float *num3 = (float *) malloc (sizeof(float));
char *op = (char *) malloc (1);
while (true) {
scanf("%f%c%f", num1, op, num2);
if (*op == *"+") { *num3 = *num1 + *num2; }
if (*op == *"-") { *num3 = *num1 - *num2; }
if (*op == *"/" || *op == *":") { *num3 = *num1 / *num2; }
if (*op == *"x" || *op == *"*") { *num3 = *num1 * *num2; }
printf("%f\n", *num3);
}
free(num1);
free(num2);
free(num3);
free(op);
return 0;
}
