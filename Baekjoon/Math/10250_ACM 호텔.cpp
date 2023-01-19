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

	int H, W, N;
	while (T--) {
		cin >> H >> W >> N;
		int ans = (N - 1) / H + 1;
		if (N % H == 0) ans += H * 100;
		else ans += (N % H) * 100;
		cout << ans << '\n';
	}

	return 0;
}