#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> trueknow(N + 1);
	queue<int> q;
	int num, node;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> node;
		q.push(node);
		trueknow[node] = 1;
	}

	vector<vector<int>> nodeSet(N + 1, vector<int>());
	vector<vector<int>> party(M + 1);
	vector<int> tempParty;

	for (int i = 0; i < M; i++) {
		cin >> num;
		
		for (int j = 0; j < num; j++) {
			cin >> node;
			tempParty.push_back(node);

			for (int k = 0; k < tempParty.size(); k++) {
				for (int l = 0; l < tempParty.size(); l++) {
					if (k == l) continue;
					if (find(nodeSet[tempParty[k]].begin(), nodeSet[tempParty[k]].end(), tempParty[l]) != nodeSet[tempParty[k]].end()) continue;
					nodeSet[tempParty[k]].push_back(tempParty[l]);
				}
			}
		}

		party[i + 1] = tempParty;
		tempParty.clear();
	}

	if (q.empty()) {
		cout << M;
		return 0;
	}

	int next;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < nodeSet[cur].size(); i++) {
			next = nodeSet[cur][i];

			if (trueknow[next] == 1) continue;
			q.push(next);
			trueknow[next] = 1;
		}
	}

	int ans = 0;
	bool isTrue;
	for (int i = 1; i <= M; i++) {
		isTrue = false;
		for (auto j : party[i]) {
			if (trueknow[j] == 1) {
				isTrue = true;
				break;
			}
		}
		if (!isTrue) ans++;
	}
	
	cout << ans;

	return 0;
}