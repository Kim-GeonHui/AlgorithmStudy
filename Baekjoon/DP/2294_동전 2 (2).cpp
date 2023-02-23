#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, num;
	cin >> n >> k;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
	}

	vector<int> arr;
	vector<int> ans(k + 1, 100000);
	auto it = s.begin();
	while (it != s.end()) {
		arr.push_back(*it);
		ans[*it] = 1;
		it++;
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] >= i) break;
			if (ans[i - arr[j]] == 0) continue;
			ans[i] = min(ans[i], ans[i - arr[j]] + 1);
		}
	}

	if (ans[k] == 100000) cout << -1;
	else cout << ans[k];

	return 0;
}