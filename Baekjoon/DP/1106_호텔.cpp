#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C, N;
	cin >> C >> N;

	vector<pair<int, int>> arr;
	int pay, cus;
	int maxCus = 0;
	for (int i = 0; i < N; i++) {
		cin >> pay >> cus;
		arr.push_back({ cus, pay });
		maxCus = max(maxCus, cus);
	}

	sort(arr.begin(), arr.end());

	vector<int> ans(C + maxCus, 1000000);
	ans[0] = 0;
	for (int i = 1; i < C + maxCus; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j].first > i) break;
			ans[i] = min(ans[i], ans[i - arr[j].first] + arr[j].second);
		}
	}

	int answer = 1000000;
	for (int i = C; i < C + maxCus; i++) {
		answer = min(answer, ans[i]);
	}
	cout << answer;

	return 0;
}