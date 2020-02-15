#include <iostream>
#include <algorithm>

using namespace std;

class Coin {
private:
	int n; //동전 개수
	int price;
	int count;
	int money[11];
public:
	void init() {
		cin >> n >> price;
		//if (!(n >= 1 && n <= 10))
		//	return false;
		for (int i = 0; i < n; i++) {
			cin >> money[i];
		}
	}

	int calc() {
		init();
		count = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (money == 0)
				break;
			if (money[j] > price)
				continue;

			count += price / money[j];
			price %= money[j];
		}
		return count;
	}
};

int main() {
	Coin coin;
	cout << coin.calc() << '\n';
}