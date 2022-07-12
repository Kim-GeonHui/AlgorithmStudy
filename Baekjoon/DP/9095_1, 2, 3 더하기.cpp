#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int T;
	cin >> T;
	vector<int> testCase(T);

	for (int i = 0; i < T; i++) {
		cin >> testCase[i];
	}

	int maxNumber = *max_element(testCase.begin(), testCase.end());

	vector<int> arr(maxNumber);
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;

	for (int i = 3; i < maxNumber; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	for (int i = 0; i < T; i++) {
		cout << arr[testCase[i] - 1] << endl;
	}
	
	return 0;
}