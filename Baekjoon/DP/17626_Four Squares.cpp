#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<bool> arr(50001, false);
	for (int i = 1; i * i <= 50000; i++) arr[i * i] = true;

	vector<int> ans(n + 1, 50001);
	ans[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			ans[i] = 1;
			continue;
		}

		for (int j = 1; j * j < i; j++) 
			ans[i] = min(ans[i], ans[i - j * j] + 1);
	}

	cout << ans[n];

	return 0;
}