#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, num;
	cin >> N;

	map<int, int> m;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (m.find(num) == m.end()) {
			m[num] = 1;
		}
		else m[num]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		if (m.find(num) == m.end()) cout << 0 << ' ';
		else cout << m[num] << ' ';
	}

	return 0;
}