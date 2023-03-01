#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> wine(n + 1);
	vector<vector<int>> ans(n + 1, vector<int>(3));
	for (int i = 1; i <= n; i++) cin >> wine[i];
	
	ans[1][1] = wine[1];
	if (n > 1) {
		ans[2][0] = ans[1][1];
		ans[2][1] = wine[2];
		ans[2][2] = wine[2] + ans[1][1];
	}
	for (int i = 3; i <= n; i++) {
		ans[i][0] = max(ans[i - 1][0], ans[i - 1][1]);
		ans[i][0] = max(ans[i - 1][2], ans[i][0]);
		ans[i][1] = ans[i - 1][0] + wine[i];
		ans[i][2] = ans[i - 1][1] + wine[i];
	}

	cout << *max_element(ans[n].begin(), ans[n].end());

	return 0;
}