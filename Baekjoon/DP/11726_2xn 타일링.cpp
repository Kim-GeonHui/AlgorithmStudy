#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dp[1001] = {};
	dp[1] = 1;
	dp[2] = 2;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) 
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	cout << dp[n];

	return 0;
}