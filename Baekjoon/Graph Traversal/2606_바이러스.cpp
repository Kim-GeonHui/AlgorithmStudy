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

	int N, E;
	cin >> N >> E;

	vector<vector<int>> nodeArr(N + 1);
	vector<int> visitArr(N + 1);
	queue<int> q;

	int u, v;
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		nodeArr[u].push_back(v);
		nodeArr[v].push_back(u);
	}

	q.push(1);
	visitArr[1] = 1;

	int tempNode;
	int answer = 0;

	while (!q.empty()) {
		tempNode = q.front();
		q.pop();

		for (auto v : nodeArr[tempNode]) {
			if (visitArr[v] == 1) continue;

			q.push(v);
			visitArr[v] = 1;
			answer++;
		}
	}

	cout << answer;

	return 0;
}