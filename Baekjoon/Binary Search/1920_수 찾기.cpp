#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	cin >> M;
	vector<int> list(M);
	for (int i = 0; i < M; i++) cin >> list[i];

	int front, end, mid;
	for (int i = 0; i < M; i++) {
		front = 0;
		end = N - 1;
		mid = (front + end) / 2;

		while (front < end) {
			if (arr[mid] == list[i]) break;
			else if (arr[mid] < list[i]) front = mid + 1;
			else end = mid - 1;
			mid = (front + end) / 2;
		}

		if (arr[mid] == list[i]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}