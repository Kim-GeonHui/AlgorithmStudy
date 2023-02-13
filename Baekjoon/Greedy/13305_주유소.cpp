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
	int idx = 0;
	int min = 1000000000;
	long long ans = 0;
	cin >> N;
	vector<int> street(N - 1);
	for (int i = 0; i < N - 1; i++) cin >> street[i];
	vector<int> oil(N);
	for (int i = 0; i < N - 1; i++) {
		cin >> oil[i];
		if (oil[i] < min) min = oil[i];
		ans += (long long)min * (long long)street[i];
	}

	cout << ans;

	return 0;
}