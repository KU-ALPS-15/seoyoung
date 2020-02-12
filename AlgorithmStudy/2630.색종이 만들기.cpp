#include<iostream>

using namespace std;

int wCount;
int bCount;
int arr[129][129];

void findcolor(int n, int top1,int top2) {
	
	int first = arr[top1][top2];

	for (int i = top1; i < top1+n; i++) {
		for (int j = top2; j < top2+n; j++) {
			if (arr[i][j] != first) {
				findcolor(n / 2, top1, top2);
				findcolor(n / 2, top1 + n / 2, top2);
				findcolor(n / 2, top1, top2 + n / 2);
				findcolor(n / 2, top1 + n / 2, top2 + n / 2);
				return;
			}
		}
	}
	if (first == 1)
		bCount++;
	else {
		wCount++;
	}
}

int main() {
	int n;
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	findcolor(n,0,0);

	cout << wCount << endl << bCount << endl;
	return 0;

}