#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, T;
	cin >> N >> M >> T;

	vector<vector<int>> map(N + 1, vector<int>(M + 1));
	vector<vector<int>> answer(N + 1, vector<int>(M + 1));
	pair<int, int> knife;
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)	knife = { i, j };
			if (map[i][j] == 1) answer[i][j] = -1;
		}
	}

	q.push({ 1,1 });
	answer[1][1] = 1;

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int nextX, nextY;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			nextX = cur.first + dx[i];
			nextY = cur.second + dy[i];

			if (nextX < 1 || N < nextX || nextY < 1 || M < nextY) continue;
			if (map[nextX][nextY] == 1) continue;
			if (answer[nextX][nextY] != 0) continue;

			q.push({ nextX, nextY });
			answer[nextX][nextY] = answer[cur.first][cur.second] + 1;
		}
	}

	int ans;
	if (answer[knife.first][knife.second] == 0 && answer[N][M] == 0) {
		cout << "Fail";
		return 0;
	}

	if (answer[knife.first][knife.second] == 0) {
		if (answer[N][M] - 1 > T) cout << "Fail";
		else cout << answer[N][M] - 1;
	}
	else if (answer[N][M] == 0) {
		ans = answer[knife.first][knife.second] + (N + M - knife.first - knife.second);
		if (ans - 1 > T) cout << "Fail";
		else cout << ans - 1;
	}
	else {
		ans = answer[knife.first][knife.second] + (N + M - knife.first - knife.second);
		ans = min(ans, answer[N][M]);

		if (ans - 1 > T) cout << "Fail";
		else cout << ans - 1;
	}

	return 0;
}