#include <stdio.h>
#include <iostream>
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

	vector<vector<int>> visitArr(n, vector<int>(m, 0));
	vector<vector<int>> drawingArr(n, vector<int>(m));

	queue<pair<int, int>> que;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	int numDrawing = 0;
	int maxLength = 0;
	int tempLength;
	pair<int, int> tempPair;
	int tempX, tempY;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> drawingArr[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (drawingArr[i][j] == 0) continue;
			if (visitArr[i][j] == 1) continue;

			visitArr[i][j] = 1;
			que.push({ i, j });

			tempLength = 1;

			while (!que.empty()) {
				tempPair = que.front();
				que.pop();

				for (int k = 0; k < 4; k++) {
					tempX = tempPair.first + dx[k];
					tempY = tempPair.second + dy[k];

					if (0 > tempX || tempX >= n || 0 > tempY || tempY >= m) continue;
					if (visitArr[tempX][tempY] == 1) continue;
					if (drawingArr[tempX][tempY] == 0) continue;

					tempLength++;
					visitArr[tempX][tempY] = 1;
					que.push({ tempX, tempY });
				}
			}

			numDrawing++;
			maxLength = (tempLength > maxLength) ? tempLength : maxLength;
		}
	}

	cout << numDrawing << '\n';
	if (numDrawing == 0) cout << 0 << '\n';
	else cout << maxLength << '\n';


	return 0;
}