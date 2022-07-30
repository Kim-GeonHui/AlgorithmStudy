#include <stdio.h>
#include <iostream>
#include <vector>
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

	vector<int> resultArr(N);
	resultArr[0] = numberArr[0];

	int tempMax = numberArr[0];

	for (int i = 1; i < N; i++) {
		resultArr[i] = max(resultArr[i - 1] + numberArr[i], numberArr[i]);

		tempMax = max(tempMax, resultArr[i]);
	}

	cout << tempMax;

	return 0;
}