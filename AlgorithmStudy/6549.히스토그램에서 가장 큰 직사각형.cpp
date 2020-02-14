
/*#include<iostream>
#include <stack>

using namespace std;

int arr[10000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = i;
		while (!s.empty() && arr[i] < arr[s.top()]) {
			int height = arr[s.top()];
			s.pop();
			int width = i; // 맨처음 i가 1일때, 2를 꺼낸다. 
			if (!s.empty()) { 
				width =( i - s.top() -1); //-1?
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
*/

#include <iostream>
#include <string>

#define SIZE 100001

using namespace std;

int init( int * data) {
	int n;
	cin >> n;
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
	}
	return n;
}

int main() {

	int data[SIZE];
	int max_area = 0;
	int height, width, area;
	int front, next;

	int n = 1;
		while (n != 0) {
			 n = init(data);
			 if (n == 0) break;
				for (int i = 0; i < n; i++) {
				height = data[i];
				front = i;
				next = i;
				while (front >= 0 && data[front] >= height)
					front--;
				while (next < n && data[next] >= height)
					next++;

				width = next - front - 1;
				area = width * height;

			if (i == 0)
				max_area = area;
			else if (max_area < area)
				max_area = area;
		}
		cout << max_area << '\n';

	}
}
