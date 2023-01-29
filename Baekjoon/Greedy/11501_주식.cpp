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

	int D, num;
	vector<long long> arr;
	long long ans, max;
	while (T--) {
		ans = 0;
		cin >> D;
		while (D--) {
			cin >> num;
			arr.push_back(num);
		}

		max = arr[arr.size() - 1];
		for (int i = arr.size() - 1; i > 0; i--) {
			if (max < arr[i - 1]) max = arr[i - 1];
			else ans += max - arr[i - 1];
		}
		cout << ans << '\n';
		arr.clear();
	}

	return 0;
}