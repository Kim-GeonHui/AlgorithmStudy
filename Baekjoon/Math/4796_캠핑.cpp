#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, P, V;
	int idx = 1;
	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;

		int a = V / P;
		int b = V % P;
		int ans = a * L;
		if (b > L) ans += L;
		else ans += b;

		cout << "Case " << idx << ": " << ans << '\n';
		idx++;
	}

	return 0;
}