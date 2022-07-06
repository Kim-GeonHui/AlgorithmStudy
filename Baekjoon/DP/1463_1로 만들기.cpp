#include <stdio.h>
#include <iostream>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int Data[1000001];

// TopDown
int TopDown(int n) {

	int tempNumber[3];

	tempNumber[0] = 1000000;
	tempNumber[1] = 1000000;
	tempNumber[2] = 1000000;

	if (n <= 3) {
		return Data[n];
	}

	if (Data[n] == 0) {
		if (n % 3 == 0) {
			tempNumber[0] = 1 + TopDown(n / 3);
		}
		
		if (n % 2 == 0) {
			tempNumber[1] = 1 + TopDown(n / 2);
		}

		tempNumber[2] = 1 + TopDown(n - 1);

		Data[n] = min({ tempNumber[0], tempNumber[1], tempNumber[2] });
	}

	return Data[n];
}

// BottomUp
int BottomUp(int n) {

	int tempNumber[3];

	if (n <= 3) {
		return Data[n];
	}

	for (int i = 4; i <= n; i++) {

		tempNumber[0] = 1000000;
		tempNumber[1] = 1000000;
		tempNumber[2] = 1000000;

		if (i % 3 == 0) {
			tempNumber[0] = 1 + Data[i / 3];
		}

		if (i % 2 == 0) {
			tempNumber[1] = 1 + Data[i / 2];
		}

		tempNumber[2] = 1 + Data[i - 1];

		Data[i] = min({ tempNumber[0], tempNumber[1], tempNumber[2] });
	}

	return Data[n];
}

int main() {
	Data[1] = 0;
	Data[2] = 1;
	Data[3] = 1;
	
	int number = 0;

	cin >> number;

	cout << TopDown(number);

	return 0;
}