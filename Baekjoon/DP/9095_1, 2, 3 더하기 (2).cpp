#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int dp[11] = {};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) 
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int T, num;
	cin >> T;
	while (T--) {
		cin >> num;
		cout << dp[num] << '\n';
	}

	return 0;
}