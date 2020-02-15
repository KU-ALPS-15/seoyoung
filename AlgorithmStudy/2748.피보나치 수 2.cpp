#include <iostream>

using namespace std;
int n;
long long arr[91];

long long Fibo(int n, long long arr[91]) {
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}
int main() {
	cin >> n;
	cout << Fibo(n, arr) << '\n';

}