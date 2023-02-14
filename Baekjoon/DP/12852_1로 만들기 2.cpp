#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int,int>> arr(N + 1);
	pair<int, int> p;

	for (int i = 1; i <= N; i++) {
		if (i * 3 <= N) {
			if (arr[i * 3].first == 0 || arr[i * 3].first > arr[i].first + 1) {
				arr[i * 3].first = arr[i].first + 1;
				arr[i * 3].second = i;
			}
		}
		if (i * 2 <= N) {
			if (arr[i * 2].first == 0 || arr[i * 2].first > arr[i].first + 1) {
				arr[i * 2].first = arr[i].first + 1;
				arr[i * 2].second = i;
			}
		}
		if (i + 1 <= N) {
			if (arr[i + 1].first == 0 || arr[i + 1].first > arr[i].first + 1) {
				arr[i + 1].first = arr[i].first + 1;
				arr[i + 1].second = i;
			}
		}
	}

	int idx = N;
	cout << arr[idx].first << '\n';
	while (idx != 1) {
		cout << idx << ' ';
		idx = arr[idx].second;
	}
	cout << 1;

	return 0;
}