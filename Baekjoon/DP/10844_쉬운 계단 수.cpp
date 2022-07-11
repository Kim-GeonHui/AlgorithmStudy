#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<int>> arr(N);
	vector<int> tempArr(10, 1);
	
	arr[0] = tempArr;
	tempArr.clear();

	int tempData = 0;

	// BottomUp
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				tempArr.push_back(arr[i - 1][1] % 1000000000);
			}
			else if (j == 9) {
				tempArr.push_back(arr[i - 1][8] % 1000000000);
			}
			else {
				tempArr.push_back((arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000);
			}
		}

		arr[i] = tempArr;
		tempArr.clear();
	}
	
	long long int max = 0;
	for (int i = 1; i < 10; i++) {
		if (max + arr[N - 1][i] >= 1000000000) {
			max -= 1000000000;
		}

		max += arr[N - 1][i];
	}
	cout << max;

	return 0;
}