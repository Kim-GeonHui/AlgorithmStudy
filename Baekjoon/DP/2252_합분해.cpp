#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<long long int> resultArr(N + 1, 1);
	vector<long long int> tempArr(N + 1);
	for (int i = 0; i < K - 2; i++) {
		fill(tempArr.begin() + 1, tempArr.end(), 0);
		tempArr[0] = 1;

		for (int j = 1; j < N + 1; j++) {
			for (int k = 0; k <= j; k++) {
				tempArr[j] += resultArr[k];
			}
		}

		resultArr.assign(tempArr.begin(), tempArr.end());
	}

	int sum = 0;
	for (int i = 0; i < N + 1; i++) {
		sum += resultArr[i] % 1000000000;
	}

	sum = (K == 1) ? 1 : sum;
	cout << sum % 1000000000;

	return 0;
}