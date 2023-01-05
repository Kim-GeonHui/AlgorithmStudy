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

	int N, M;
	cin >> N >> M;

	vector<vector<char>> map(N + 1, vector<char>(M + 1));
	vector<vector<int>> fire(N + 1, vector<int>(M + 1));
	vector<vector<int>> jihun(N + 1, vector<int>(M + 1));
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				fire[i][j] = -1;
				jihun[i][j] = -1;
				continue;
			}
			if (map[i][j] == 'J') {
				jihun[i][j] = 1;
				q1.push({ i,j });
				continue;
			}
			if (map[i][j] == 'F') {
				fire[i][j] = 1;
				q2.push({ i,j });
				continue;
			}
		}
	}

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int nextX, nextY;

	while (!q2.empty()) {
		auto cur = q2.front();
		q2.pop();

		for (int i = 0; i < 4; i++) {
			nextX = cur.first + dx[i];
			nextY = cur.second + dy[i];

			if (nextX < 1 || N < nextX || nextY < 1 || M < nextY) continue;
			if (fire[nextX][nextY] != 0) continue;

			q2.push({ nextX, nextY });
			fire[nextX][nextY] = fire[cur.first][cur.second] + 1;
		}
	}

	bool isEnd = false;
	while (!q1.empty()) {
		auto cur = q1.front();
		q1.pop();

		for (int i = 0; i < 4; i++) {
			nextX = cur.first + dx[i];
			nextY = cur.second + dy[i];

			if (nextX < 1 || N < nextX || nextY < 1 || M < nextY) {
				cout << jihun[cur.first][cur.second];
				return 0;
			}
			if (jihun[nextX][nextY] != 0) continue;
			if (jihun[cur.first][cur.second] + 1 >= fire[nextX][nextY] && fire[nextX][nextY] != 0) continue;

			q1.push({ nextX, nextY });
			jihun[nextX][nextY] = jihun[cur.first][cur.second] + 1;
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}