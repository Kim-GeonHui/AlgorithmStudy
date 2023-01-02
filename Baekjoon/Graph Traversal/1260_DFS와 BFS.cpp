#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V, u, v, tempNode;
	cin >> N >> M >> V;

	vector<vector<int>> nodeArr(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		nodeArr[u].push_back(v);
		nodeArr[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) 
		sort(nodeArr[i].rbegin(), nodeArr[i].rend());

	vector<int> visitDFSArr(N + 1);
	vector<int> visitBFSArr(N + 1);

	queue<int> q;
	stack<int> s;

	q.push(V);
	s.push(V);

	visitBFSArr[V] = 1;

	while (!s.empty()) {
		tempNode = s.top();
		s.pop();

		if (visitDFSArr[tempNode] == 1) continue;
		visitDFSArr[tempNode] = 1;

		cout << tempNode << ' ';

		for (auto v : nodeArr[tempNode]) {
			if (visitDFSArr[v] == 1) continue;
			s.push(v);
		}
	}

	cout << '\n';

	for (int i = 1; i <= N; i++)
		sort(nodeArr[i].begin(), nodeArr[i].end());

	while (!q.empty()) {
		tempNode = q.front();
		q.pop();
		cout << tempNode << ' ';

		for (auto v : nodeArr[tempNode]) {
			if (visitBFSArr[v] == 1) continue;

			q.push(v);
			visitBFSArr[v] = 1;
		}
	}

	return 0;
}