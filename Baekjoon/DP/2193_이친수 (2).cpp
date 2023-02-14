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

	vector<pair<long long, long long>> arr;
	pair<long long, long long> p;
	arr.push_back(p);
	p.first = 1;
	arr.push_back(p);
	if (N > 1) {
		p.first = 0;
		p.second = 1;
		arr.push_back(p);
	}
	for (int i = 3; i <= N; i++) {
		p.first = arr[i - 1].second;
		p.second = arr[i - 1].first + arr[i - 1].second;
		arr.push_back(p);
	}

	cout << arr[N].first + arr[N].second;

	return 0;
}