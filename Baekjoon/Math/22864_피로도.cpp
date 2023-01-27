#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C, M;
	cin >> A >> B >> C >> M;

	int pi = 0;
	int time = 0;
	int ans = 0;
	while (time < 24) {
		time++;

		if (pi + A <= M) {
			ans += B;
			pi += A;
		}
		else pi = max(0, pi - C);
	}

	cout << ans;

	return 0;
}