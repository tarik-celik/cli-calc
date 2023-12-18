#include <stdio.h>
int main() {
float num1, num2, num3;
char op;                                                      
  while(1) {                                                    
    scanf("%f %c %f", &num1, &op, &num2);
if (op == *"+") {
num3 = num1 + num2;
printf("%.3f",num3);
}
if (op == *"-") {
num3 = num1 - num2;
printf("%.3f", num3);
}
if (op == *"/") {
num3 = num1 / num2;
printf("%.3f", num3);
}
if (op == *"x") {
num3 = num1 * num2;
printf("%.3f", num3);
}
printf("\n");
}
return 0;
}
