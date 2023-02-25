#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N + 1);
	vector<int> ans(N + 1);
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		ans[i] = arr[i];
		answer = max(answer, arr[i]);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i - 1; j > 0; j--) {
			if (arr[j] < arr[i]) {
				ans[i] = max(ans[i], ans[j] + arr[i]);
				answer = max(answer, ans[i]);
			}
		}
	}

	cout << answer;

	return 0;
}