#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

long long gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int n;
	while (T--) {
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		cout << ans << '\n';
	}

	return 0;
}