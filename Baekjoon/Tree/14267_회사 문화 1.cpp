#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<vector<int>> node;
vector<int> score;
vector<int> ans;

void DFS(int num, int sco) {
	ans[num] = sco;

	for (int next : node[num]) 
		DFS(next, sco + score[next]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	node.assign(n + 1, vector<int>());
	score.assign(n + 1, 0);
	ans.assign(n + 1, 0);

	int num;
	cin >> num;
	for (int i = 2; i <= n; i++) {
		cin >> num;
		node[num].push_back(i);
	}

	int i, w;
	for (int j = 0; j < m; j++) {
		cin >> i >> w;
		score[i] += w;
	}

	DFS(1, 0);

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';

	return 0;
}