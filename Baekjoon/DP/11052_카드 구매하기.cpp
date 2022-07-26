#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> cardArr(N);
	for (int i = 0; i < N; i++) {
		cin >> cardArr[i];
	}

	vector<int> resultArr(N);
	resultArr[0] = cardArr[0];
	for (int i = 1; i < N; i++) {
		resultArr[i] = cardArr[i];
		for (int j = i - 1; (i - 1) / 2 <= j; j--) {
			resultArr[i] = max(resultArr[j] + resultArr[i - 1 - j], resultArr[i]);
		}
	}
	
	cout << resultArr[N - 1];

	return 0;
}