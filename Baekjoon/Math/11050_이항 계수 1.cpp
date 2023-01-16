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

	int N, K;
	cin >> N >> K;

	int dp[11];
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 10; i++) 
		dp[i] = i * dp[i - 1];

	cout << (dp[N] / dp[K]) / dp[N - K];

	return 0;
}