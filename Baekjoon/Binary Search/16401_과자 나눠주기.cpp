#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector<int> snack;

long long solve(int t) {
	long long ans = 0;
	for (int i = 0; i < snack.size(); i++) ans += snack[i] / t;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	snack.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> snack[i];
	sort(snack.begin(), snack.end());

	if (solve(1) < M) {
		cout << 0;
		return 0;
	}

	int front, end, mid;
	front = 1;
	end = 1000000000;
	mid = (front + end) / 2;

	while (front < end) {
		if (solve(mid) >= M) front = mid + 1;
		else end = mid;
		mid = (front + end) / 2;
	}
	
	cout << end - 1;
	return 0;
}