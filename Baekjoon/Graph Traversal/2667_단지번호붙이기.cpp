#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	string str;
	vector<vector<int>> map(N + 1, vector<int>(N + 1));
	vector<vector<int>> visit(N + 1, vector<int>(N + 1));
	stack<pair<int, int>> s;
	vector<int> answer;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= N; j++) {
			map[i][j] = str[j - 1] - '0';
		}
	}

	int tempNum, tempX, tempY;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) continue;
			if (visit[i][j] == 1) continue;

			s.push({ i, j });

			tempNum = 0;
			while (!s.empty()) {
				auto temp = s.top();
				s.pop();
				if (visit[temp.first][temp.second] == 1) continue;
				visit[temp.first][temp.second] = 1;
				tempNum++;

				for (int i = 0; i < 4; i++) {
					tempX = temp.first + dx[i];
					tempY = temp.second + dy[i];

					if (1 > tempX || N < tempX || 1 > tempY || N < tempY) continue;
					if (map[tempX][tempY] == 0) continue;
					if (visit[tempX][tempY] == 1) continue;

					s.push({ tempX, tempY });
				}
			}

			answer.push_back(tempNum);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << '\n';

	return 0;
}