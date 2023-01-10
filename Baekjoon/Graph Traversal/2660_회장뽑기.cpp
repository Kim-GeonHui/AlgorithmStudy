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

	int N, u, v;
	cin >> N;

	vector<vector<int>> node(N + 1, vector<int>());
	vector<int> visit;
	vector<int> score(N + 1);
	vector<int> ans;
	queue<int> q;
	int maxScore, ansScore;

	while (true) {
		cin >> u >> v;

		if (u == -1 && v == -1) break;
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

			for (int i = 0; i < node[cur].size(); i++) {
				next = node[cur][i];

				if (visit[next] != 0) continue;
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}

		maxScore = *max_element(visit.begin(), visit.end());
		score[i] = maxScore;

		visit.clear();
	}

	ansScore = *min_element(++score.begin(), score.end());

	for (int i = 1; i <= N; i++) 
		if (score[i] == ansScore) ans.push_back(i);
	
	cout << ansScore - 1 << ' ' << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}