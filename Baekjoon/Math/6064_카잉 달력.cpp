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

	int T;
	cin >> T;

	int M, N, x, y;
	while (T--) {
		cin >> M >> N >> x >> y;
		if (x == M) x = 0;
		if (y == N) y = 0;

		int num = M / gcd(M, N) * N;
		int ans = 0;
		for (int i = x; i <= num; i += M) {
			if (i == 0) continue;
			if (i % N == y) {
				ans = i;
				break;
			}
		}

		if (ans != 0) cout << ans << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}