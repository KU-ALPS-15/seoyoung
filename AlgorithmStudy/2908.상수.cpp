#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int num1, num2;
	cin >> num1 >> num2;
	
	int new1=0, new2=0;
	int count = 2;
	while (num1) {
		new1 += (num1 % 10) * pow(10, count);
		count--;
		num1 = num1 / 10;
	}
	count = 2;
	while (num2) {
		new2 += (num2 % 10) * pow(10, count);
		count--;
		num2 = num2 / 10;
	}
	if (new1 > new2)
		cout << new1 << '\n';
	else
		cout << new2 << '\n';
	
}