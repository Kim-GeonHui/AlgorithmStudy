#include <stdio.h>
#include <iostream>
#pragma warning (disable:4996)

using namespace std;

int fiboData[46];

// TopDown
int fibonachTopDown(int n) {

	if (n <= 2) {
		return 1;
	}

	if (fiboData[n] == 0) {
		fiboData[n] = fibonachTopDown(n - 1) + fibonachTopDown(n - 2);
	}

	return fiboData[n];
}

// BottomUp
void fibonachBottomUp(int n) {

	for (int i = 2; i <= n; i++) {
		fiboData[i] = fiboData[i - 1] + fiboData[i - 2];
	}
}

int main() {

	fiboData[0] = 0;
	fiboData[1] = 1;

	int number = 0;

	cin >> number;

	cout << fibonachTopDown(number);

	return 0;
}