#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

vector<vector<int>> node;
vector<int> visit;
map<pair<int, int>, int> length;

void DFS(int num, int len) {
	for (int i : node[num]) {
		if (visit[i] != 0) continue;

		visit[i] = len + length[{num, i}];
		DFS(i, visit[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	node.assign(N + 1, vector<int>());

	int u, v, l;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> l;
		node[u].push_back(v);
		node[v].push_back(u);
		length[{u, v}] = l;
		length[{v, u}] = l;
	}

	for (int i = 0; i < M; i++) {
		visit.assign(N + 1, 0);
		cin >> u >> v;

		visit[u] = 1;
		DFS(u, 0);
		cout << visit[v] << '\n';

		visit.clear();
	}

	return 0;
}