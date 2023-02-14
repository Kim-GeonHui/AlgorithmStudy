#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int dp[1000001] = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	queue<int> q;
	q.push(N); 

	if (N == 1) {
		cout << 0;
		return 0;
	}

	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur % 3 == 0 && dp[cur / 3] == 0) {
			q.push(cur / 3);
			dp[cur / 3] = dp[cur] + 1;
		}
		if (cur % 2 == 0 && dp[cur / 2] == 0) {
			q.push(cur / 2);
			dp[cur / 2] = dp[cur] + 1;
		}
		if (cur - 1 > 1 && dp[cur - 1] == 0) {
			q.push(cur - 1);
			dp[cur - 1] = dp[cur] + 1;
		}

		if (dp[1] != 0) {
			cout << dp[1];
			return 0;
		}
	}

	return 0;
}