#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M;

	vector<vector<int>> arr(N + 1, vector<int>(M + 1));
	vector<vector<int>> ans(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) 
			ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + arr[i][j];
	}

	cin >> K;
	int x1, x2, y1, y2;

	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << ans[x2][y2] - ans[x1 - 1][y2] - ans[x2][y1 - 1] + ans[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}