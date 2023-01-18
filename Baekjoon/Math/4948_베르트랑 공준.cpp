#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	while (true) {
		cin >> n;
		if (n == 0) break;

		vector<bool> visit(2 * n + 1);
		visit[1] = true;
		for (long long i = 2; i <= 2 * n; i++) {
			if (visit[i] == true) continue;
			for (long long j = i * i; j <= 2 * n; j += i)
				visit[j] = true;
		}

		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (visit[i] == false) ans++;
		}

		cout << ans << '\n';
	}

	return 0;
}