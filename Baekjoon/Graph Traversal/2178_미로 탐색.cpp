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
	string str;

	vector<vector<int>> maze(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++)
			maze[i][j] = str[j - 1] - '0';
	}

	vector<vector<int>> result(N + 1, vector<int>(M + 1, -1));
	queue<pair<int, int>> q;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	q.push({ 1,1 });
	result[1][1] = 1;
	int tempX, tempY;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			tempX = cur.first + dx[i];
			tempY = cur.second + dy[i];

			if (1 > tempX || N < tempX || 1 > tempY || M < tempY) continue;
			if (maze[tempX][tempY] == 0) continue;
			if (result[tempX][tempY] != -1) continue;

			q.push({ tempX, tempY });
			result[tempX][tempY] = result[cur.first][cur.second] + 1;
		}
	}

	cout << result[N][M];

	return 0;
}