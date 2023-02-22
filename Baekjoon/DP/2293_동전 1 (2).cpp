#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> coin(n);
	for (int i = 0; i < n; i++) cin >> coin[i];
	sort(coin.begin(), coin.end());

	vector<int> ans(k + 1);
	for (int c : coin) {
		if (c > k) break;
		ans[c] += 1;
		for (int i = c + 1; i <= k; i++) {
			if (ans[i - c] == 0) continue;
			ans[i] += ans[i - c];
		}
	}

	cout << ans[k];

	return 0;
}