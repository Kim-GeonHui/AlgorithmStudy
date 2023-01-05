#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

vector<int> visit;
vector<vector<pair<int, int>>> node;
int answer = 0;

void DFS(int num, int len) {
	if (answer < len) answer = len;

	for (int i = 0; i < node[num].size(); i++) {
		if (visit[node[num][i].first] == 1) continue;

		visit[node[num][i].first] = 1;
		DFS(node[num][i].first, len + node[num][i].second);
		visit[node[num][i].first] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	node.assign(N + 1, vector<pair<int, int>>());
	visit.assign(N + 1, 0);

	int u, v, d;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> d;
		node[u].push_back({ v, d });
		node[v].push_back({ u, d });
	}

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		DFS(i, 0);
		visit[i] = 0;
	}

	cout << answer;

	return 0;
}