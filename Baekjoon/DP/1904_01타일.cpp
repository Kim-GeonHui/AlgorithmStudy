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

	vector<int> ans(N + 1);
	ans[1] = 1;
	if (N > 1) ans[2] = 2;
	for (int i = 3; i <= N; i++)
		ans[i] = (ans[i - 1] + ans[i - 2]) % 15746;

	cout << ans[N];

	return 0;
}