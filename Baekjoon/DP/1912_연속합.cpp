#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
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

	vector<int> arr;
	int maxSum = numberArr[0];
	int maxIndex = 0;
	arr.push_back(numberArr[0]);

	for (int i = 1; i < N; i++) {
		for (int j = maxIndex; j <= i; j++) {
			if (i == j) {
				arr.push_back(numberArr[i]);
				if (arr[i] > maxSum) {
					maxSum = arr[i];
					maxIndex = i;
				}
			}
			else {
				arr[j] += numberArr[i];
				if (arr[j] > maxSum) {
					maxSum = arr[j];
					maxIndex = j;
				}
			}
		}
	}

	cout << maxSum;

	return 0;
}