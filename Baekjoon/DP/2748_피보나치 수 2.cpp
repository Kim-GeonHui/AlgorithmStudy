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

	vector<long long> ans(n + 1);
	ans[1] = 1;
	for (int i = 2; i <= n; i++) ans[i] = ans[i - 1] + ans[i - 2];
	cout << ans[n];

	return 0;
}