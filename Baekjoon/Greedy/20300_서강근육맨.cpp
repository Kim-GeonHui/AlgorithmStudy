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
	vector<long long> health(N);
	for (int i = 0; i < N; i++) cin >> health[i];
	long long ans = 0;
	int idx = 0;

	sort(health.begin(), health.end());
	if (health.size() % 2 == 0) idx = health.size() - 1;
	else {
		idx = health.size() - 2;
		ans = health[idx + 1];
	}

	for (int i = 0; i <= health.size() / 2; i++) {
		ans = max(ans, health[i] + health[idx]);
		idx--;
	}

	cout << ans;

	return 0;
}