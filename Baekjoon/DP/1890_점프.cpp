#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int> (N));
	vector<vector<long long int>> numberArr(N, vector<long long int>(N));

	numberArr[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 0) {
				if (i + arr[i][j] < N)
					numberArr[i + arr[i][j]][j] += numberArr[i][j];
				if (j + arr[i][j] < N)
					numberArr[i][j + arr[i][j]] += numberArr[i][j];
			}
		}
	}

	cout << numberArr[N - 1][N - 1];
	
	return 0;
}