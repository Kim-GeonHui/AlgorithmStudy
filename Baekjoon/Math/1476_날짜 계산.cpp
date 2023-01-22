#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int E, S, M;
	cin >> E >> S >> M;
	if (E == 15) E = 0;
	if (S == 28) S = 0;
	if (M == 19) M = 0;
	
	int num = 15 / gcd(15, 28) * 28 * 19;
	for (int i = E; i <= num; i += 15) {
		if (i == 0) continue;
		if (i % 28 != S) continue;
		if (i % 19 != M) continue;

		cout << i;
		return 0;
	}

	return 0;
}