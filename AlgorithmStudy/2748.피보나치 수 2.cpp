#include <iostream>

using namespace std;

const int mod = 100000;
const int p = 1500000;
int main() {
	long long n;
	cin >> n;
	long arr[p] = { 0,1 };
	for (int i = 0; i < p; i++) {
		arr[i] = (arr[i - 2]%mod + arr[i - 1]%mod);
	}

	cout << arr[n % p] << '\n';
	

}