#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, W;
	cin >> T >> W;

	vector<int> arr(T + 1);
	for (int i = 1; i <= T; i++) cin >> arr[i];

	vector<vector<int>> ans(T + 1, vector<int>(W + 1));
	for (int i = 1; i <= T; i++) {
		if (arr[i] == 1) ans[i][0] = ans[i - 1][0] + 1;
		else ans[i][0] = ans[i - 1][0];
		for (int j = 1; j <= W; j += 2) {
			if (i < j) break;
			if (arr[i] == 2) ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]) + 1;
			else ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]);
		}
		for (int j = 2; j <= W; j += 2) {
			if (i < j) break;
			if (arr[i] == 1) ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]) + 1;
			else ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]);
		}
	}

	cout << *max_element(ans[T].begin(), ans[T].end());

	return 0;
}