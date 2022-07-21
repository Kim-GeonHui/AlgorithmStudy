#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> coinArr(N);
	for (int i = 0; i < N; i++) {
		cin >> coinArr[i];
	}

	vector<long long int> resultArr(K + 1);

	for (int i = 0; i < N; i++) {
		for (int j = coinArr[i]; j <= K; j++) {
			if (j == coinArr[i])
				resultArr[coinArr[i]] += 1;

			resultArr[j] += resultArr[j - coinArr[i]];
		}
	}

	cout << resultArr[K];

	return 0;
}