#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n;
	cin >> T;

	while (T--) {
		cin >> n;

		vector<bool> prime(n + 1, false);
		prime[1] = true;

		for (int i = 2; i <= n; i++) {
			if (prime[i]) continue;
			for (int j = i * i; j <= n; j += i)
				prime[j] = true;
		}

		pair<int, int> ans;
		for (int i = 2; i <= n / 2; i++)
			if (!prime[i] && !prime[n - i]) ans = { i, n - i };
	
		cout << ans.first << ' ' << ans.second << '\n';
	}

	return 0;
}