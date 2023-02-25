#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; i++) cin >> arr[i];

	queue<int> q;
	q.push(1);
	vector<bool> ans(N + 1, false);
	ans[1] = true;
	
	int next;
	int temp;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = cur + 1; i <= N; i++) {
			temp = (i - cur) * (1 + abs(arr[i] - arr[cur]));
			
			if (temp > K) continue;
			if (ans[i] == true) continue;

			ans[i] = true;
			q.push(i);

			if (i == N) {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
	return 0;
}