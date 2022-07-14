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
	vector<int> numberArr(K);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		
		if (arr[i] - 1 < K)
			numberArr[arr[i] - 1] += 1;
	}

	sort(arr.begin(), arr.end());
	
	int tempIndex = 0;
	for (int i = arr[0]; i < K; i++) {
		for (int j = 0; j < tempIndex + 1; j++) {
			if (numberArr[i - arr[j]] != 0) {
				numberArr[i] = numberArr[i - arr[j]] + 1;
			}
		}
	}

	cout << numberArr[K - 1];
	
	return 0;
}