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

	int M, N;
	cin >> M >> N;

	vector<vector<int>> map(N + 1, vector<int>(M + 1));
	vector<vector<int>> answer(N + 1, vector<int>(M + 1));
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			answer[i][j] = map[i][j];
			if (map[i][j] == 1) q.push({ i,j });
		}
	}

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int tempX, tempY;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			tempX = cur.first + dx[i];
			tempY = cur.second + dy[i];

			if (tempX < 1 || N < tempX || tempY < 1 || M < tempY) continue;
			if (map[tempX][tempY] != 0) continue;
			if (answer[tempX][tempY] > 0) continue;

			q.push({ tempX, tempY });
			answer[tempX][tempY] = answer[cur.first][cur.second] + 1;
		}
	}

	int mini = 0;
	int tempMin;
	for (int i = 1; i <= N; i++) {
		if (find(++answer[i].begin(), answer[i].end(), 0) != answer[i].end()) {
			cout << -1 << '\n';
			return 0;
		}
		tempMin = *max_element(answer[i].begin(), answer[i].end());
		mini = (tempMin > mini) ? tempMin : mini;
	}

	cout << mini - 1;

	return 0;
}