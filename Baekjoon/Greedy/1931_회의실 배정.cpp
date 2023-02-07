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

	vector<pair<int, int>> arr;
	pair<int, int> temp;
	for (int i = 0; i < N; i++) {
		cin >> temp.second >> temp.first;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	int end = arr[0].first;
	int ans = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i].second < end) continue;
		end = arr[i].first;
		ans++;
	}
	cout << ans;

	return 0;
}