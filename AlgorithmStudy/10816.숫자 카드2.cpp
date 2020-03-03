#include <iostream>
#include <cstdio>
#include <algorithm>
#define SIZE 500001
using namespace std;
int arr[SIZE];

int upper_bound(int target, int size) {
	int start, end, mid;
	start = 0, end = size - 1;

	while (end>start) {
		mid = (start + end) / 2;
		if (arr[mid] > target) //upper_bound 함수 :target초과위치 
			end = mid; 
		else 
			start = mid +1;
	}
	return end;
}
int lower_bound(int target, int size) {
	int start, end, mid;
	start = 0, end = size - 1;
	while (end>start) {
		mid = (start + end) / 2;
		if (arr[mid] >= target) //lower_bound 함수 :target이상
			end = mid;
		else
			start = mid + 1;
	}
	return end;

}
int main() {
	int N,M,temp,lower,upper;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	
	cin >> M;
	int* m_arr = new int[M];
	int* result = new int[M];

	for (int i = 0; i < M; i++) {
		cin >> m_arr[i];
		result[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		lower = lower_bound(m_arr[i], N);
		upper = upper_bound(m_arr[i], N);
		if (upper == N - 1 && arr[N - 1] == m_arr[i])
			upper++;
		result[i] = upper - lower;
	}

	for (int i = 0; i < M; i++) {
		printf("%d ", result[i]);
	}

}