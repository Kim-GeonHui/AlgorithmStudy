#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	vector<int> ans(N);
	ans[0] = arr[0];
	for (int i = 1; i < N; i++) ans[i] = ans[i - 1] + arr[i];

	int i, j;
	while (M--) {
		cin >> i >> j;
		if (i == 1) cout << ans[j - 1] << '\n';
		else cout << ans[j - 1] - ans[i - 2] << '\n';
	}

	return 0;
}