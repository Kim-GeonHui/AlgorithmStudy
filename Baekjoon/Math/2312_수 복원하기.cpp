#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<int> arr(N + 1, 0);
		vector<bool> visit(N + 1, false);

		int i = 2;
		while (i * i <= N) {
			if (N % i != 0) {
				i++;
				continue;
			}
			visit[i] = true;
			arr[i] += 1;
			N /= i;
		}
		if (N != 1) {
			visit[N] = true;
			arr[N] += 1;
		}

		for (int i = 2; i < visit.size(); i++) {
			if (!visit[i]) continue;
			cout << i << ' ' << arr[i] << '\n';
		}
	}

	return 0;
}