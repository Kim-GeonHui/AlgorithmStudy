#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, temp;
	cin >> N;
	vector<int> floor(N);
	for (int i = 0; i < N; i++) cin >> floor[i];
	vector<pair<int, int>> arr;
	pair<int, int> p = { 0, 0 };
	
	p.first = floor[0];
	arr.push_back(p);
	if (N > 1) {
		p.first = floor[1];
		p.second += floor[1] + floor[0];
		arr.push_back(p);
	}
	for (int i = 2; i < N; i++) {
		temp = arr[i - 2].first;
		temp = max(temp, arr[i - 2].second);
		p.first = temp + floor[i];
		p.second = arr[i - 1].first + floor[i];
		arr.push_back(p);
	}

	cout << max(arr[N - 1].first, arr[N - 1].second);

	return 0;
}