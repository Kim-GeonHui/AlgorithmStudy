#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int T, P;
	vector<pair<pair<int, int>, int>> arr;
	pair<pair<int, int>, int> TP;
	pair<int, int> p;
	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		p.first = i + T - 1;
		p.second = i;
		TP.first = p;
		TP.second = P;
		arr.push_back(TP);
	}

	sort(arr.begin(), arr.end());

	int idx = 0;
	int temp;
	vector<int> ans(N + 1);
	for (int i = 1; i <= N; i++) {
		if (idx == N) break;

		temp = ans[i - 1];
		while (i == arr[idx].first.first) {
			temp = max(temp, arr[idx].second + ans[arr[idx].first.second - 1]);
			idx++;
			if (idx == N) break;
		}
		ans[i] = temp;
	}

	cout << ans[N];

	return 0;
}