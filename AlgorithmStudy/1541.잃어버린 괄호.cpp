#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 51
using namespace std;

class Brac {
private:
	string input = "";
	string temp = "";
	int minus;
	int result;
public:
	bool init() {
		cin >> input;
		if (input.length() >= SIZE) {
			return false;
		}
	}
	int calc() {
		init();
		minus = 0;
		result = 0;
		for (int i = 0; i <=input.length(); i++) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '\0') {
				if (minus == 1) { result -= stoi(temp); }
				else  { result += stoi(temp); }
				temp = "";
				if (input[i] == '-') { minus = 1; }
			}
			else {
				temp += input[i];
			}
		}
		return result;
	}
};


int main() {
	Brac brac;
	cout<<brac.calc();
}