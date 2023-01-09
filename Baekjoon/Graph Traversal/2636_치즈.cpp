#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> map(N + 1, vector<int>(M + 1));
	vector<vector<int>> origin(N + 1, vector<int>(M + 1));
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) map[i][j] = -1;
		}
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	
	pair<int, int> ans = { 0, 0 };
	int tempX, tempY;

	while (true) {
		q1.push({ 1,1 });
		origin[1][1] = 1;

		while (!q1.empty()) {
			auto cur = q1.front();
			q1.pop();

			for (int i = 0; i < 4; i++) {
				tempX = cur.first + dx[i];
				tempY = cur.second + dy[i];

				if (tempX < 1 || N < tempX || tempY < 1 || M < tempY) continue;
				if (origin[tempX][tempY] == 1) continue;
				if (map[tempX][tempY] == 1) continue;

				if (map[tempX][tempY] == -1) {
					q2.push({ tempX, tempY });
					map[tempX][tempY] = 1;
					continue;
				}

				origin[tempX][tempY] = 1;
				q1.push({ tempX, tempY });
			}
		}

		origin.clear();
		origin.assign(N + 1, vector<int>(M + 1));

		if (q2.empty()) break;

		ans.first++;
		ans.second = 0;

		while (!q2.empty()) {
			map[q2.front().first][q2.front().second] = 0;
			q2.pop();
			ans.second++;
		}
	}

	cout << ans.first << '\n';
	cout << ans.second;

	return 0;
}