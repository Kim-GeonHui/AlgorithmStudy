#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, q, t, k;
	int node1, node2;
	int count;

	map<int, int> nodeMap;
	
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;

		if (nodeMap.find(node1) == nodeMap.end()) nodeMap[node1] = 1;
		else nodeMap[node1] += 1;
		if (nodeMap.find(node2) == nodeMap.end()) nodeMap[node2] = 1;
		else nodeMap[node2] += 1;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		count = 0;
		cin >> t >> k;
		if (t == 1) {
			if (nodeMap[k] == 1) cout << "no" << '\n';
			else cout << "yes" << '\n';
		}
		else if (t == 2) {
			cout << "yes" << '\n';
		}
	}

	return 0;
}