#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, temp, num;
	
	cin >> T;
	while (T--) {
		cin >> N;
		vector<bool> visit(N + 1, 0);
		visit[1] = true;
		for (int i = 2; i <= N; i++) {
			num = i;
			for (int j = 1; j * j <= num; j++) {
				if (num % j == 0) temp = j;
			}
			if (temp * temp == num) visit[i] = true;
		}

		int ans = 0;
		for (bool i : visit)
			if (i) ans++;

		cout << ans << '\n';
	}

	return 0;
}