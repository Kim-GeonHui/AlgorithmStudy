#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B, V;
	cin >> A >> B >> V;

	long long ans = 1;
	V -= A;
	long long temp = V / (A - B);
	V %= (A - B);
	if (V > 0) ans++;

	cout << ans + temp;

	return 0;
}