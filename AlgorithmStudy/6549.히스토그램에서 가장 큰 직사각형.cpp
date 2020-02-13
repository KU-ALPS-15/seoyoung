#include<iostream>
#include <stack>

using namespace std;

int arr[10000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = i;
		while (!s.empty() && arr[i] < arr[s.top()] {
			int height = arr[s.top()];
			s.pop();
			int width = i; // 맨처음 i가 1일때, 2를 꺼낸다. 
			if (!s.empty()) { 
				width =( i - s.top() ); //-1?
			}
			if (ans < width * height) {
				ans = width * height;
			}
		}
		s.push(i);
	}

	while (!s.empty()) {
		int height = arr[s.top()];
		s.pop();
		int width = n;
		if (!s.empty())
			width = n - s.top() - 1;
		if (ans < width * height) {
			ans = width * height;
		}
	}

	printf("%d\n", ans);


	
}