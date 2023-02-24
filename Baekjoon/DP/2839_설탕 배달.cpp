#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> ans(N + 1, 5000);
	ans[3] = 1;
	if (N > 4) ans[5] = 1;
	for (int i = 6; i <= N; i++) 
		ans[i] = min(ans[i - 3], ans[i - 5]) + 1;
	
	if (ans[N] >= 5000) cout << -1;
	else cout << ans[N];

	return 0;
}