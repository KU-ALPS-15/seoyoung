#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
bool myComparison(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);

		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), myComparison);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	return 0;

}