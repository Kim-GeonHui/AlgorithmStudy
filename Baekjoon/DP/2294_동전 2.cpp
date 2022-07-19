#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> coinArr(N);
	for (int i = 0; i < N; i++) {
		cin >> coinArr[i];
	}

	vector<int> resultArr(K + 1, 10001);
	resultArr[0] = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = coinArr[i]; j <= K; j++) {
			resultArr[j] = min(resultArr[j], resultArr[j - coinArr[i]] + 1);
		}
	}

	if (resultArr[K] == 10001)
		cout << -1;
	else
		cout << resultArr[K];

	return 0;
}