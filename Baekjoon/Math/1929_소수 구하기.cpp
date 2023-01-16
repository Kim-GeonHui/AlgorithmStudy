#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

vector <bool> visit;
vector<int> prime;

void isPrime(int m, int n) {
	visit[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (visit[i] == 1) continue;
		for (int j = 2 * i; j <= n; j += i)
			visit[j] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (visit[i] == 1) continue;
		if (i < m) continue;
		prime.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	visit.assign(N + 1, 0);
	isPrime(M, N);

	for (int i : prime) cout << i << '\n';

	return 0;
}