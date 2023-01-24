#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a[2];
	int b[2];
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];

	int num1 = a[0] * b[1] + a[1] * b[0];
	int num2 = a[1] * b[1];
	int temp = gcd(num1, num2);

	cout << num1 / temp << ' ' << num2 / temp;

	return 0;
}