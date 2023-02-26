#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	vector<vector<long long>> ans(N, vector<long long>(21));
	ans[1][arr[0]] = 1;
	int dx[2] = { 1,-1 };
	int next;
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k < 2; k++) {
				next = j + dx[k] * arr[i];
				if (next < 0 || 20 < next) continue;
				ans[i + 1][next] += ans[i][j];
			}
		}
	}
	cout << ans[N - 1][arr[N - 1]];

	return 0;
}