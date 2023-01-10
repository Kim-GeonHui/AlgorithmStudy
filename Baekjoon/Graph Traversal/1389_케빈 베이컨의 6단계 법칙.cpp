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

	vector<vector<int>> node(N + 1, vector<int>());
	vector<int> visit;
	vector<int> score(N + 1);
	queue<int> q;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		node[u].push_back(v);
		node[v].push_back(u);
	}

	int next;
	for (int i = 1; i <= N; i++) {
		visit.assign(N + 1, 0);
		
		q.push(i);
		visit[i] = 1;
		
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int j = 0; j < node[cur].size(); j++) {
				next = node[cur][j];

				if (visit[next] != 0) continue;

				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}

		for (int j = 1; j <= N; j++)
			score[i] += visit[j] - 1;

		visit.clear();
	}

	int min = *min_element(++score.begin(), score.end());
	cout << find(score.begin(), score.end(), min) - score.begin();

	return 0;
}