#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, I;
	cin >> N >> K >> I;

	K -= 1;
	I -= 1;

	int temp;
	int ans = 1;

	while (true) {
		temp = pow(2, ans);
		if (K / temp == I / temp) break;
		ans++;
	}

	cout << ans;

	return 0;
}