#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M, num;
	cin >> T;

	vector<int> arr;
	vector<int> ans;
	while (T--) {
		cin >> N;
		arr.assign(N, 0);
		for (int i = 0; i < N; i++) cin >> arr[i];

		cin >> M;
		ans.assign(M + 1, 0);
		for (int coin : arr) {
			if (coin <= M) ans[coin] += 1;
			for (int i = coin + 1; i <= M; i++) ans[i] += ans[i - coin];
		}

		cout << ans[M] << '\n';

		arr.clear();
		ans.clear();
	}

	return 0;
}