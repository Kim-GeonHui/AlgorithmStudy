#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<int> data(1000);

int main() {

	int N;
	cin >> N;

	vector<vector<int>> arr(N);
	vector<int> tempArr(10, 1);
	arr[0] = tempArr;

	int tempData;

	// BottomUp
	for (int i = 1; i < N; i++) {
		tempArr.clear();

		for (int j = 0; j < 10; j++) {
			tempData = 0;

			for (int k = j; k < 10; k++) {
				tempData += arr[i - 1][k] % 10007;
			}

			tempArr.push_back(tempData % 10007);
		}

		arr[i] = tempArr;
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += arr[N - 1][i];
	}

	cout << result % 10007;

	return 0;
}