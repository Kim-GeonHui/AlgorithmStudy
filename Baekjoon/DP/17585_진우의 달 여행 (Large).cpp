#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N + 1, vector<int>(M + 1));
	vector<vector<vector<int>>> ans(N + 1, vector<vector<int>>(M + 1, vector<int>(3, 100000000)));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) 
			cin >> arr[i][j];
	}

	for (int i = 1; i <= M; i++)
		for (int j = 0; j < 3; j++) ans[1][i][j] = arr[1][i];

	ans[2][1][1] = arr[1][1] + arr[2][1];
	ans[2][1][2] = arr[1][2] + arr[2][1];
	for (int i = 2; i < M; i++) {
		for (int j = 0; j < 3; j++) {
			ans[2][i][j] = arr[2][i] + arr[1][i - 1 + j];
		}
	}
	ans[2][M][0] = arr[2][M] + arr[1][M - 1];
	ans[2][M][1] = arr[2][M] + arr[1][M];

	for (int i = 3; i <= N; i++) {
		ans[i][1][1] = ans[i - 1][1][2] + arr[i][1];
		ans[i][1][2] = min(ans[i - 1][2][0], ans[i - 1][2][1]) + arr[i][1];
		for (int j = 2; j <= M - 1; j++) {
			ans[i][j][0] = min(ans[i - 1][j - 1][1], ans[i - 1][j - 1][2]) + arr[i][j];
			ans[i][j][1] = min(ans[i - 1][j][0], ans[i - 1][j][2]) + arr[i][j];
			ans[i][j][2] = min(ans[i - 1][j + 1][0], ans[i - 1][j + 1][1]) + arr[i][j];
		}
		ans[i][M][0] = min(ans[i - 1][M - 1][1], ans[i - 1][M - 1][2]) + arr[i][M];
		ans[i][M][1] = ans[i - 1][M][0] + arr[i][M];
	}

	int answer = 100000000;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 3; j++) 
			answer = min(answer, ans[N][i][j]);
	}

	cout << answer;

	return 0;
}