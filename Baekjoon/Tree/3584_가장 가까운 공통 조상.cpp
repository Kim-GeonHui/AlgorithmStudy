#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#pragma warning (disable:4996)

using namespace std;

vector<vector<int>> node;
vector<int> temp1;
vector<int> temp2;
vector<int> temp;
vector<int> visit;

void DFS(int num, int tar) {
	if (num == tar) temp1 = temp;

	for (int i : node[num]) {
		if (visit[i] == 1) continue;

		visit[i] = 1;
		temp.push_back(i);
		DFS(i, tar);
		temp.pop_back();
		visit[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, u, v;
	cin >> T;

	while (T--) {
		cin >> N;

		node.assign(N + 1, vector<int>());
		vector<int> findRoot(N + 1);
		for (int i = 0; i < N - 1; i++) {
			cin >> u >> v;
			node[u].push_back(v);
			findRoot[v] = 1;
		}

		cin >> u >> v;
		int root = find(++findRoot.begin(), findRoot.end(), 0) - findRoot.begin();
		
		visit.clear();
		visit.assign(N + 1, 0);
		visit[root] = 1;
		temp.clear();
		temp.push_back(root);
		DFS(root, u);
		temp2 = temp1;

		visit.clear();
		visit.assign(N + 1, 0);
		visit[root] = 1;
		temp.clear();
		temp.push_back(root);
		DFS(root, v);

		int ans;
		for (int i = temp2.size() - 1; i >= 0; i--) {
			if (find(temp1.begin(), temp1.end(), temp2[i]) != temp1.end()) {
				ans = temp2[i];
				break;
			}
		}

		cout << ans << '\n';

		temp1.clear();
		temp2.clear();
		node.clear();
	}

	return 0;
}