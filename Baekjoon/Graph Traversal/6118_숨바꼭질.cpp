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

	int N, M, u, v;
	cin >> N >> M;
	
	vector<vector<int>> node(N + 1, vector<int>());
	vector<int> visit(N + 1);
	queue<int> q;

	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	q.push(1);
	visit[1] = 1;

	int next;
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

	int max = *max_element(++++visit.begin(), visit.end());
	int index = find(visit.begin(), visit.end(), max) - visit.begin();
	int num = 0;
	for (int i = 2; i <= N; i++)
		if (visit[i] == max) num++;

	cout << index << ' ' << max - 1 << ' ' << num;

	return 0;
}