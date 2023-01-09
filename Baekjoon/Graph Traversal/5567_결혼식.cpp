#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

vector<vector<int>> node;
vector<int> visit;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	node.assign(n + 1, vector<int>());
	visit.assign(n + 1, 0);

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	visit[1] = 1;
	queue<int> q;
	q.push(1);

	int next;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < node[cur].size(); i++) {
			next = node[cur][i];

			if (visit[next] != 0) continue;

			q.push(next);
			visit[next] = visit[cur] + 1;
		}
	}

	for (int i = 2; i <= n; i++)
		if (visit[i] != 0 && visit[i] < 4) ans++;

	cout << ans;

	return 0;
}