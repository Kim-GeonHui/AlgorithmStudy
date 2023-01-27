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

	int T, A, B;
	cin >> T;

	while (T--) {
		cin >> A >> B;
		cout << A / gcd(A, B) * B << '\n';
	}

	return 0;
}