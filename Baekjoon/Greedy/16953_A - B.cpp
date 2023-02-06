#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	cin >> A >> B;

	int ans = 1;
	while (A < B) {
		if (B % 10 == 1) {
			B /= 10;
			ans++;
		}
		else {
			if (B % 2 == 1) {
				cout << -1;
				return 0;
			}
			else {
				B /= 2;
				ans++;
			}
		}
	}

	if (A == B) cout << ans;
	else cout << -1;

	return 0;
}