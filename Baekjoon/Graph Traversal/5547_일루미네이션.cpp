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

	int W, H;
	cin >> W >> H;

	vector<vector<int>> map(H + 2, vector<int>(W + 2));
	vector<vector<int>> visit(H + 2, vector<int>(W + 2));
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++) cin >> map[i][j];

	int dx[6] = { -1, -1, 0, 0, 1, 1 };
	int dy1[6] = { 0, 1, -1, 1, 0, 1 };
	int dy2[6] = { -1, 0, -1, 1, -1, 0 };
	int nextX, nextY;
	int ans = 0;
	queue<pair<int, int>> q;

	q.push({ 0,0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			nextX = cur.first + dx[i];
			if (cur.first % 2 == 0) nextY = cur.second + dy2[i];
			else nextY = cur.second + dy1[i];

			if (nextX < 0 || H + 1 < nextX || nextY < 0 || W + 1 < nextY) continue;
			if (visit[nextX][nextY] == 1) continue;
			if (map[nextX][nextY] == 1) {
				ans++;
				continue;
			}

			q.push({ nextX,nextY });
			visit[nextX][nextY] = 1;
		}
	}

	cout << ans;

	return 0;
}