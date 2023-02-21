#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, num;
	cin >> N >> M;

	vector<bool> vip(41, false);
	for (int i = 0; i < M; i++) {
		cin >> num;
		vip[num] = true;
	}

	vector<int> ans1(N + 1);
	vector<int> ans2(N + 1);
	ans1[1] = 1;
	if (N > 1) {
		ans1[2] = 1;
		if (!vip[1] && !vip[2]) ans2[2] = 1;
	}
	for (int i = 3; i <= N; i++) {
		ans1[i] = ans1[i - 1] + ans2[i - 1];
		if (!(vip[i - 1] || vip[i])) ans2[i] = ans1[i - 2] + ans2[i - 2];
	}
	
	cout << ans1[N] + ans2[N];

	return 0;
}