#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		vector<bool> prime(N + 1, false);
		prime[1] = true;
		for (long long i = 2; i <= N; i++) {
			if (prime[i]) continue;
			for (long long j = i * i; j <= N; j += i)
				prime[j] = true;
		}

		int ans = 0;
		for (int i = 2; i <= N / 2; i++)
			if (!prime[i] && !prime[N - i]) ans++;

		cout << ans << '\n';
	}

	return 0;
}