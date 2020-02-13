#include<iostream>

using namespace std;

const int MAX = 100;

int arr1[MAX][MAX], arr2[MAX][MAX];
int result[MAX][MAX];
int main() {

	int N, M, K;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr1[i][j];
		}
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> arr2[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int r = 0; r < M; r++) {
				result[i][j] += (arr1[i][r] * arr2[r][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << result[i][j] << " ";
		}
		cout << '\n';
	}
}