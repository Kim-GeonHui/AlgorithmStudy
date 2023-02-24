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

	vector<int> ans(N + 1);
	int temp;
	if (N > 1) ans[2] = 1;
	for (int i = 5; i <= N; i++) {
		temp = max(ans[i - 1], ans[i - 3]);
		temp = max(temp, ans[i - 4]);
		if (temp == 0) ans[i] = 1;
	}

	if (ans[N] == 1) cout << "CY";
	else cout << "SK";

	return 0;
}