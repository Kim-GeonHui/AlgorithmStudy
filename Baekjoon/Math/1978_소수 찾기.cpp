#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

bool isPrime(int n) {
	if (n == 1) return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int num;
	int ans = 0;
	while (N--) {
		cin >> num;
		if (isPrime(num)) ans++;
	}
	cout << ans;

	return 0;
}