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

	vector<vector<int>> map(N + 1, vector<int>(M + 1));
	queue<pair<int, int>> q;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) q.push({ i,j });
		}
	}

	int H, W, Sr, Sc, Fr, Fc;
	cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

	for (int i = N; i > N - H + 1; i--)
		for (int j = 1; j <= M; j++) map[i][j] = -1;

	for (int i = M; i > M - W + 1; i--)
		for (int j = 1; j <= N; j++) map[j][i] = -1;

	int X, Y;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				X = cur.first - i;
				Y = cur.second - j;

				if (X < 1 || N < X || Y < 1 || M < Y) continue;
				if (map[X][Y] == -1) continue;

				map[X][Y] = -1;
			}
		}
	}

	q.push({ Sr,Sc });
	map[Sr][Sc] = 1;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			X = cur.first + dx[i];
			Y = cur.second + dy[i];

			if (X < 1 || N < X || Y < 1 || M < Y) continue;
			if (map[X][Y] != 0) continue;

			q.push({ X,Y });
			map[X][Y] = map[cur.first][cur.second] + 1;

			if (X == Fr && Y == Fc) {
				cout << map[X][Y] - 1;
				return 0;
			}
		}
	}

	cout << -1;

	return 0;
}