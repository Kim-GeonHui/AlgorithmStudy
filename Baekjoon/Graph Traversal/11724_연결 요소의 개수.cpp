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

	int N, M, u, v;
	cin >> N >> M;

	queue<int> q;

	vector<vector<int>> adjArr(N + 1);
	vector<int> visitArr(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		adjArr[u].push_back(v);
		adjArr[v].push_back(u);
	}

	int answer = 0;
	int tempV = 0;

	for (int i = 1; i <= N; i++) {
		if (visitArr[i] == 1) continue;

		answer++;

		q.push(i);
		visitArr[i] = 1;

		while (!q.empty()) {
			tempV = q.front();
			q.pop();

			for (int j = 0; j < adjArr[tempV].size(); j++) {
				if (visitArr[adjArr[tempV][j]] == 1) continue;

				q.push(adjArr[tempV][j]);
				visitArr[adjArr[tempV][j]] = 1;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}