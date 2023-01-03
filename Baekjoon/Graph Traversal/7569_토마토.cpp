#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, H;
	cin >> M >> N >> H;

	vector<vector<vector<int>>> map(N + 1, vector<vector<int>>(M + 1, vector<int>(H + 1)));
	vector<vector<vector<int>>> visit(N + 1, vector<vector<int>>(M + 1, vector<int>(H + 1)));
	queue<tuple<int, int, int>> q;

	for (int k = 1; k <= H; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j][k];
				visit[i][j][k] = map[i][j][k];
				if (map[i][j][k] == 1) q.push(make_tuple(i, j, k));
			}
		}
	}

	int dx[6] = { 1, 0, 0, -1, 0, 0 };
	int dy[6] = { 0, 1, 0, 0, -1, 0 };
	int dz[6] = { 0, 0, 1, 0, 0, -1 };
	int tempX, tempY, tempZ;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			tempX = get<0>(cur) + dx[i];
			tempY = get<1>(cur) + dy[i];
			tempZ = get<2>(cur) + dz[i];

			if (tempX < 1 || N < tempX || tempY < 1 || M < tempY || tempZ < 1 || H < tempZ) continue;
			if (map[tempX][tempY][tempZ] != 0) continue;
			if (visit[tempX][tempY][tempZ] > 0) continue;

			q.push(make_tuple(tempX, tempY, tempZ));
			visit[tempX][tempY][tempZ] = visit[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}
	}

	int min = 0;
	int tempMin;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j].end() != find(++visit[i][j].begin(), visit[i][j].end(), 0)) {
				cout << -1;
				return 0;
			}
			tempMin = *max_element(visit[i][j].begin(), visit[i][j].end());
			min = max(min, tempMin);
		}
	}

	cout << min - 1;

	return 0;
}