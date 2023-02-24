#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;

	while (T--) {
		cin >> N >> M;
		if (M == N || N == 0) cout << 1 << '\n';
		else if (N == M - 1 || N == 1) cout << M << '\n';
		else {
			vector<vector<int>> ans(M + 1, vector<int>(M + 1));
			ans[1][0] = 1;
			ans[1][1] = 1;
			for (int i = 2; i <= M; i++) {
				ans[i][0] = 1;
				ans[i][i] = 1;
				ans[i][1] = i;
				ans[i][i - 1] = i;
			}
			for (int i = 3; i <= M; i++) {
				for (int j = 2; j < i; j++) 
					ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
			}
			cout << ans[M][N] << '\n';
		}
	}

	return 0;
}