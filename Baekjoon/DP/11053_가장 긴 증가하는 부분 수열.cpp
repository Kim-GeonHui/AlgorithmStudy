#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> numberArr(N);
	for (int i = 0; i < N; i++) {
		cin >> numberArr[i];
	}

	vector<vector<int>> arr(N);
	vector<vector<int>> maxNumberArr(N);
	for (int i = 0; i < N; i++) {
		arr[i] = vector<int>(pow(2, i + 1));
		maxNumberArr[i] = vector<int>(pow(2, i + 1));
	}

	arr[0][0] = 0;
	arr[0][1] = 1;
	maxNumberArr[0][1] = numberArr[0];
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < pow(2, i + 1); j++) {
			if (j % 2 == 0) {
				arr[i][j] = arr[i - 1][j / 2];
				maxNumberArr[i][j] = maxNumberArr[i - 1][j / 2];
			}
			else if (maxNumberArr[i - 1][j / 2] < numberArr[i]) {
				arr[i][j] = arr[i - 1][j / 2] + 1;
				maxNumberArr[i][j] = numberArr[i];
			}
			else {
				arr[i][j] = arr[i - 1][j / 2];
				maxNumberArr[i][j] = maxNumberArr[i - 1][j / 2];
			}
		}
	}

	int result = 0;
	int tempMax = 0;
	for (int i = 0; i < N; i++) {
		tempMax = *max_element(arr[i].begin(), arr[i].end());
		if (tempMax > result)
			result = tempMax;
	}

	cout << tempMax;

	return 0;
}