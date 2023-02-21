#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	vector<int> arr;
	int maxNumber = 0;
	while (T--) {
		cin >> N;
		arr.push_back(N);
		maxNumber = max(maxNumber, N);
	}

	vector<int> ans(maxNumber + 1);
	ans[1] = 1;
	if (maxNumber > 1) ans[2] = 2;
	if (maxNumber > 2) ans[3] = 4;
	
	for (int i = 4; i <= maxNumber; i++) {
		ans[i] = (ans[i - 1] + ans[i - 2]) % 1000000009;
		ans[i] = (ans[i] + ans[i - 3]) % 1000000009;
	}

	for (int idx : arr) cout << ans[idx] << '\n';

	return 0;
}