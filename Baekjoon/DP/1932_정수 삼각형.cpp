#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	int tempNumber = 0;

	vector<vector<int>> numberArr(N);
	vector<int> tempArr;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tempNumber;
			tempArr.push_back(tempNumber);
		}
		numberArr[i] = tempArr;
		tempArr.clear();
	}

	vector<int> resultArr = numberArr[N - 1];
	for (int i = N - 2; 0 <= i; i--) {
		for (int j = 0; j <= i; j++) {
			tempNumber = max(resultArr[j], resultArr[j + 1]);
			resultArr[j] = numberArr[i][j] + tempNumber;
		}
	}

	cout << resultArr[0];

	return 0;
}