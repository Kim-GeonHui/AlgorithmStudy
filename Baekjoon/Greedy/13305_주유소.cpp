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
	vector<long long> street(N - 1);
	vector<long long> oil(N);
	for (int i = 0; i < N - 1; i++) cin >> street[i];
	for (int i = 0; i < N; i++) cin >> oil[i];

	int last = N - 1;
	long long ans = 0;
	int idx;

	while (last > 0) {
		idx = min_element(oil.begin(), oil.begin() + last) - oil.begin();
		for (int i = idx; i < last; i++) ans += street[i] * oil[idx];
		last = idx;
	}

	cout << ans;

	return 0;
}