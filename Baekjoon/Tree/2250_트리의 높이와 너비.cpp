#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

vector<vector<int>> node;
vector<int> number;
vector<int> depth;
vector<vector<int>> depthArr;
int index = 0;

void preorder(int num) {
	if (node[num][0] != -1) preorder(node[num][0]);
	index++;
	depthArr[depth[num]].push_back(num);
	number[num] = index;
	if (node[num][1] != -1) preorder(node[num][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	node.assign(N + 1, vector<int>(2));
	number.assign(N + 1, 0);
	depth.assign(N + 1, 0);
	vector<int> findRoot(N + 1);
	queue<int> q;

	int n, l, r;
	for (int i = 1; i <= N; i++) {
		cin >> n >> l >> r;
		node[n][0] = l;
		node[n][1] = r;
		if (l != -1) findRoot[l] = 1;
		if (r != -1) findRoot[r] = 1;
	}

	int root = find(++findRoot.begin(), findRoot.end(), 0) - findRoot.begin();
	depth[root] = 1;
	q.push(root);

	int next;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			next = node[cur][i];

			if (next == -1) continue;
			if (depth[next] != 0) continue;

			q.push(next);
			depth[next] = depth[cur] + 1;
		}
	}

	int maxDepth = *max_element(++depth.begin(), depth.end());
	depthArr.assign(maxDepth + 1, vector<int>());

	preorder(root);

	vector<int> answer(maxDepth + 1);
	for (int i = 1; i <= maxDepth; i++) 
		answer[i] = number[depthArr[i][depthArr[i].size() - 1]] - number[depthArr[i][0]];

	int ans2 = *max_element(++answer.begin(), answer.end());
	int ans1 = find(++answer.begin(), answer.end(), ans2) - answer.begin();
	cout << ans1 << ' ' << ans2 + 1;

	return 0;
}