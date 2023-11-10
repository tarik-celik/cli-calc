#include <iostream>
#include <string>
using std::cout, std::cin, std::string, std::endl;
int main() {
double num1, num2, num3;
string x;
while (true) {
cin >> num1 >> x >> num2;
if (x == "+") {num1 + num2 = num3;}
if (x == "-") {num1 - num2 = num3;}
if (x == "/" or x == ":") {num1 / num2 = num3;}      if (x == "x" or x == "*") {num1 * num2 = num3;}
cout << num3 << endl;}}