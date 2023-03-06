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

	cin >> M;
	vector<int> list(M);
	for (int i = 0; i < M; i++) cin >> list[i];

	sort(arr.begin(), arr.end());
	for (int target : list) {
		cout << binary_search(arr.begin(), arr.end(), target) << ' ';
	}

	return 0;
}