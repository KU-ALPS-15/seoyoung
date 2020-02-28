#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	int left = 1;
	int right = k;
	int mid,ans;
	while (left <= right) {
		int cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < k)
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}