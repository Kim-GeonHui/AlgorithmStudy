#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, R;
	cin >> N >> R;

	vector<vector<int>> node(N + 1, vector<int>());
	map<pair<int, int>, int> length;

	int a, b, d;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> d;
		node[a].push_back(b);
		node[b].push_back(a);
		length[{a, b}] = d;
		length[{b, a}] = d;
	}

	vector<int> visit(N + 1);
	int ans1 = 0;
	int ans2 = 0;

	if (N == 1) {
		cout << ans1 << ' ' << ans2;
		return 0;
	}
	int G;
	int temp = node[R][0];
	visit[R] = 1;
	if (node[R].size() != 1) G = R;
	else {
		visit[temp] = 1;
		while (node[temp].size() == 2) {
			for (int next : node[temp]) {
				if (visit[next] == 1) continue;
				visit[next] = 1;
				temp = next;
				break;
			}
		}
		G = temp;
	}

	fill(visit.begin(), visit.end(), 0);

	queue<int> q;
	q.push(R);
	visit[R] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int next : node[cur]) {
			if (visit[next] != 0) continue;

			visit[next] = visit[cur] + length[{cur, next}];
			q.push(next);
		}
	}

	ans1 = visit[G] - visit[R];
	ans2 = *max_element(visit.begin(), visit.end()) - visit[G];
	
	cout << ans1 << ' ' << ans2;

	return 0;
}