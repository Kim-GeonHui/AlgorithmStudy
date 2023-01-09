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

	int R, C, N;
	cin >> R >> C >> N;
	string s;

	vector<vector<int>> map(R + 1, vector<int>(C + 1));
	vector<vector<int>> visit(R + 1, vector<int>(C + 1));
	queue<pair<int, int>> q;

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int nextX, nextY;

	for (int i = 1; i <= R; i++) {
		cin >> s;
		for (int j = 1; j <= C; j++) {
			if (s[j - 1] == '.') map[i][j] = 0;
			else {
				map[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	if (N == 1) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] == 0) cout << '.';
				else cout << 'O';
			}
			cout << '\n';
		}
	}
	else if (N % 2 == 0) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				cout << 'O';
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < N / 2; i++) {
			visit.clear();
			visit.assign(R + 1, vector<int>(C + 1));

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();

				visit[cur.first][cur.second] = 1;
				for (int i = 0; i < 4; i++) {
					nextX = cur.first + dx[i];
					nextY = cur.second + dy[i];

					if (nextX < 1 || R < nextX || nextY < 1 || C < nextY) continue;
					if (visit[nextX][nextY] == 1) continue;

					visit[nextX][nextY] = 1;
				}
			}

			for (int i = 1; i <= R; i++) 
				for (int j = 1; j <= C; j++) 
					if (visit[i][j] == 0) q.push({ i,j });
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (visit[i][j] == 1) cout << '.';
				else cout << 'O';
			}
			cout << '\n';
		}
	}

	return 0;
}