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

	int n, m;
	cin >> n >> m;

	pair<int, int> target;
	vector<vector<int>> map(n + 1, vector<int>(m + 1));
	vector<vector<int>> visit(n + 1, vector<int>(m + 1, -1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				visit[i][j] = 0;
				continue;
			}
			if (map[i][j] == 2) target = { i, j };
		}
	}

	queue<pair<int, int>> q;
	q.push({ target.first, target.second });
	visit[target.first][target.second] = 0;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int tempX, tempY;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			tempX = cur.first + dx[i];
			tempY = cur.second + dy[i];

			if (tempX < 1 || n < tempX || tempY < 1 || m < tempY) continue;
			if (map[tempX][tempY] == 0) continue;
			if (visit[tempX][tempY] >= 0) continue;

			visit[tempX][tempY] = visit[cur.first][cur.second] + 1;
			q.push({ tempX, tempY });
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << visit[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}