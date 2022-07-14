#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	vector<int> numberArr(K);
	for (int i = 0; i < N; i++) {
		if (arr[i] - 1 < K)
			numberArr[arr[i] - 1] = 1;
	}

	int tempIndex = 0;
	int tempMin;

	for (int i = arr[0]; i < K; i++) {
		if (numberArr[i] != 0)
			tempIndex++;
		else {
			tempMin = 0;
			for (int j = 0; j < tempIndex + 1; j++) {
				if (numberArr[i - arr[j]] != 0) {
					tempMin = 1 + numberArr[i - arr[j]];
					if (numberArr[i] == 0) {
						numberArr[i] = tempMin;
					}
					else {
						numberArr[i] = min(tempMin, numberArr[i]);
					}
				}
			}
		}
	}
	
	if (numberArr[K - 1] == 0) {
		cout << -1;
	}
	else {
		cout << numberArr[K - 1];
	}
	
	return 0;
}