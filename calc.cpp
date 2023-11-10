#include <iostream>
#include <string>
using std::cout, std::string, std::cin, std::endl;
int main() {
double num1, num2, num3;
string x;
while (true) {
cin >> num1 >> x >> num2;
if (x == "+") {num3 = num1 + num2;}
if (x == "-") {num3 = num1 - num2;}
if (x == "/" or x == ":") {num3 = num1 / num2;}                                  if (x == "x" or x == "*") {num3 = num1 * num2;}
cout << num3 << endl;}
return 0;
}