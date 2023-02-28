#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(M + 1));
	vector<vector<int>> up(N + 1, vector<int>(M + 1));
	vector<vector<int>> down(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
	
	up[N][1] = map[N][1];
	for (int i = N - 1; i > 0; i--) {
		up[i][1] = up[i + 1][1] + map[i][1];
	}
	for (int j = 2; j <= M; j++) {
		up[N][j] = up[N][j - 1] + map[N][j];
		for (int i = N - 1; i > 0; i--) {
			up[i][j] = max(up[i + 1][j], up[i][j - 1]) + map[i][j];
		}
	}

	down[1][1] = up[1][1] + map[1][1];
	for (int i = 2; i <= N; i++) {
		down[i][1] = max(down[i - 1][1], up[i][1]) + map[i][1];
	}
	for (int j = 2; j <= M; j++) {
		down[1][j] = max(up[1][j], down[1][j - 1]) + map[1][j];
		for (int i = 2; i <= N; i++) {
			down[i][j] = max(up[i][j], down[i][j - 1]);
			down[i][j] = max(down[i][j], down[i - 1][j]) + map[i][j];
		}
	}

	cout << down[N][M];

	return 0;
}