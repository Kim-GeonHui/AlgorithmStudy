#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<int> parentArr;
vector<vector<int>> nodeArr;

void DFS(int tar) {
	for (auto v : nodeArr[tar]) {
		if (v == 1) continue;
		if (parentArr[v] != 0) continue;
		
		parentArr[v] = tar;
		DFS(v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	nodeArr.assign(N + 1, vector<int>());
	parentArr.assign(N + 1, 0);

	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		nodeArr[u].push_back(v);
		nodeArr[v].push_back(u);
	}

	DFS(1);

	for (int i = 2; i <= N; i++)
		cout << parentArr[i] << '\n';

	return 0;
}