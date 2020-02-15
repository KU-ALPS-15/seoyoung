#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1001
//map 에 순서, 시간 저장하면 value 뺄 때 vector 로 변환해서 빼야한다,,
using namespace std;

class ATM {
private:
	int n;
	int min_value;
	int person[SIZE];

public:
	int result() {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> person[i];
		}
		sort(person, person + n);
		min_value = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				min_value += person[j];
			}
		}
		return min_value;
	}
};

int main() {
	ATM atm;
	cout << atm.result() << '\n';
}