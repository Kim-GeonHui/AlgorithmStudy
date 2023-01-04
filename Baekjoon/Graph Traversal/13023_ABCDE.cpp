#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<vector<int>> node;
vector<int> visit;

int answer = 0;
int N, M;

void DFS(int cnt, int num) {
	if (cnt == 5) {
		answer = 1;
		return;
	}

	for (int i = 0; i < node[num].size(); i++) {
		if (visit[node[num][i]] == 1) continue;
		visit[node[num][i]] = 1;
		DFS(cnt + 1, node[num][i]);
		visit[node[num][i]] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	node.assign(N, vector<int> ());
	visit.assign(N, 0);

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		if (answer == 1) break;
		visit[i] = 1;
		DFS(1, i);
		visit[i] = 0;
	}

	cout << answer;

	return 0;
}