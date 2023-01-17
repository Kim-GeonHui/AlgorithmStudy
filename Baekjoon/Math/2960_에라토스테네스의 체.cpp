#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<bool> visit(N + 1, false);
	visit[1] = true;
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (visit[i] == true) continue;
		ans++;
		if (ans == K) {
			cout << i;
			return 0;
		}
		for (int j = i * i; j <= N; j += i) {
			if (visit[j] == true) continue;
			visit[j] = true;
			ans++;
			if (ans == K) {
				cout << j;
				return 0;
			}
		}
	}

	return 0;
}