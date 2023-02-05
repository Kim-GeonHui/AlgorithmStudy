#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	int ans = 0;
	cin >> num;

	while (num >= 10) {
		num -= 5;
		ans++;
	}
	if (num < 5 && num % 2 == 1)
		ans = -1;
	else if (num % 2 == 0)
		ans += num / 2;
	else
		ans += 1 + (num - 5) / 2;

	cout << ans;

	return 0;
}