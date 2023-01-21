#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long a, b;
	cin >> n;

	while (n--) {
		cin >> a >> b;
		cout << a / gcd(a, b) * b << '\n';
	}

	return 0;
}