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

	int count = 1;
	while (N != 0) {
		vector<vector<int>> map(N + 1, vector<int>(3));
		vector<vector<int>> ans(N + 1, vector<int>(3));

		for (int i = 1; i <= N; i++) 
			cin >> map[i][0] >> map[i][1] >> map[i][2];

		ans[1][0] = map[1][0];
		ans[1][1] = map[1][1];
		ans[1][2] = map[1][2] + ans[1][1];

		ans[2][0] = ans[1][1] + map[2][0];
		ans[2][1] = min(ans[1][1], ans[1][2]);
		ans[2][1] = min(ans[2][1], ans[2][0]) + map[2][1];
		ans[2][2] = min(ans[1][1], ans[1][2]);
		ans[2][2] = min(ans[2][2], ans[2][1]) + map[2][2];

		for (int i = 3; i <= N; i++) {
			ans[i][0] = min(ans[i - 1][0], ans[i - 1][1]) + map[i][0];
			ans[i][1] = min(ans[i][0], ans[i][0] - map[i][0]);
			ans[i][1] = min(ans[i][1], ans[i - 1][2]) + map[i][1];
			ans[i][2] = min(ans[i - 1][1], ans[i - 1][2]);
			ans[i][2] = min(ans[i][2], ans[i][1]) + map[i][2];
		}

		cout << count << '.' << ' ' << ans[N][1] << '\n';
		count++;

		cin >> N;
	}

	return 0;
}