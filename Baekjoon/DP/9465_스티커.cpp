#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		vector<int> arr1(N);
		vector<int> arr2(N);
		for (int i = 0; i < N; i++) cin >> arr1[i];
		for (int i = 0; i < N; i++) cin >> arr2[i];

		vector<int> ans1(N);
		vector<int> ans2(N);
		ans1[0] = arr1[0];
		ans2[0] = arr2[0];
		if (N > 1) {
			ans1[1] = ans2[0] + arr1[1];
			ans2[1] = ans1[0] + arr2[1];
		}
		for (int i = 2; i < N; i++) {
			ans1[i] = max(ans2[i - 1], ans2[i - 2]) + arr1[i];
			ans2[i] = max(ans1[i - 1], ans1[i - 2]) + arr2[i];
		}
		cout << max(ans1[N - 1], ans2[N - 1]) << '\n';
	}

	return 0;
}