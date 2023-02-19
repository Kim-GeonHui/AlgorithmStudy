#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	long long ans[101];
	ans[1] = 1;
	ans[2] = 1;
	ans[3] = 1;
	ans[4] = 2;
	ans[5] = 2;
	for (int i = 6; i <= 100; i++) 
		ans[i] = ans[i - 1] + ans[i - 5];

	int N;
	while (T--) {
		cin >> N;
		cout << ans[N] << '\n';
	}

	return 0;
}