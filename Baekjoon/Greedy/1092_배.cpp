#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> crane(N);
	for (int i = 0; i < N; i++) cin >> crane[i];
	sort(crane.rbegin(), crane.rend());

	cin >> M;
	vector<int> box(M);
	vector<bool> boxCheck(M, false);
	for (int i = 0; i < M; i++) cin >> box[i];
	sort(box.rbegin(), box.rend());

	if (box[0] > crane[0]) {
		cout << -1;
		return 0;
	}

	int check = 0;
	int idx = 0;
	int ans = 0;
	while (check < M) {
		ans++;
		idx = 0;
		for (int i = 0; i < M; i++) {
			if (idx == N) break;
			if (box[M - 1] > crane[idx]) break;
			if (boxCheck[i]) continue;
			if (crane[idx] < box[i]) continue;
			boxCheck[i] = true;
			check++;
			idx++;
		}
	}

	cout << ans;

	return 0;
}