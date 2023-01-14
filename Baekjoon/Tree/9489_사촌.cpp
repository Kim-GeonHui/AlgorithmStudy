#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	while (true) {
		cin >> n >> k;
		if (n == 0 && k == 0) break;

		map<int, vector<int>> node;
		map<int, int> parent;
		vector<int> arr;
		int num;
		int root;
		for (int i = 0; i < n; i++) {
			cin >> num;
			arr.push_back(num);
		}

		root = arr[0];
		int a = 0;
		int b = 1;
		while (b < n - 1) {
			node[arr[a]].push_back(arr[b]);
			parent[arr[b]] = arr[a];
			if (arr[b] != arr[b + 1] - 1) a++;
			b++;
		}
		node[arr[a]].push_back(arr[b]);
		parent[arr[b]] = arr[a];

		int temp = parent[k];
		if (temp == root) {
			cout << 0 << '\n';
			continue;
		}
		

		int p = parent[temp];
		int ans = 0;
		auto it = node[p].begin();
		while (it != node[p].end()) {
			if (*it == temp) {
				it++;
				continue;
			}
			ans += node[*it].size();
			it++;
		}
		cout << ans << '\n';
	}


	return 0;
}