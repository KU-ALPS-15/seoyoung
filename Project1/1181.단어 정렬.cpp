#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
bool comp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}
	return a < b;
}
int main() {

	int n;
	cin >> n;

	vector<string> v;
	string saved;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		v.push_back(word);
	}
	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < n; i++) {
		if (saved != v[i]) {
			cout << v[i] << '\n';
		}
		saved = v[i];
	}

}