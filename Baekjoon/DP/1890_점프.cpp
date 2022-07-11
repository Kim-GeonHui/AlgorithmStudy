#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int N;

vector<vector<int>> dataArr(100, vector<int>(100, -1));

int topDown(int x, int y, vector<vector<int>> arr) {

	int tempIndex = arr[x][y];

	if (x == N - 1 && y == N - 1) {
		dataArr[x][y] = 0;

		if (N > 9) {
			for (int i = 1; i < 10; i++) {
				if (i == arr[N - i - 1][N - 1]) {
					dataArr[x][y] += topDown(x - i, y, arr);
				}
				if (i == arr[N - 1][N - i - 1]) {
					dataArr[x][y] += topDown(x, y - i, arr);
				}
			}
		}
		else {
			for (int i = 1; i < N - 1; i++) {
				if (i == arr[N - i - 1][N - 1]) {
					dataArr[x][y] += topDown(x - i, y, arr);
				}
				if (i == arr[N - 1][N - i - 1]) {
					dataArr[x][y] += topDown(x, y - i, arr);
				}
			}
		}
	}
	
	if (dataArr[x][y] == -1) {
		dataArr[x][y] = 0;

		if (x - arr[x][y] >= 0) {
			dataArr[x][y] += topDown(x - tempIndex, y, arr);
		}
		if (y - arr[x][y] >= 0) {
			dataArr[x][y] += topDown(x, y - tempIndex, arr);
		}
	}

	return dataArr[x][y];
}

int main() {
	
	cin >> N;

	vector<vector<int>> arr(N, vector<int> (N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dataArr[arr[0][0]][0] = 1;
	dataArr[0][arr[0][0]] = 1;

	// TopDown
	cout << topDown(N - 1, N - 1, arr);

	return 0;
}