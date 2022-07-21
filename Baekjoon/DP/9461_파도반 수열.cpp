#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int T;
	cin >> T;

	vector<int> arr(T);
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}

	int max = *max_element(arr.begin(), arr.end());

	vector<long long int> numberArr(max);
	numberArr[0] = 1;
	for (int i = 1; i < max; i++) {
		if (i == 1 || i == 2)
			numberArr[i] = 1;
		else if (i == 3 || i == 4) {
			numberArr[i] = 2;
		}
		else {
			numberArr[i] = numberArr[i - 1] + numberArr[i - 5];
		}
	}

	for (int i = 0; i < T; i++) {
		cout << numberArr[arr[i] - 1] << endl;
	}

	return 0;
}