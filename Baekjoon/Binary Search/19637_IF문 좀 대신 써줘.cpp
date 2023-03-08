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
	cin >> N >> M;
	string str;
	
	vector<string> style(N);
	vector<int> upper(N);
	for (int i = 0; i < N; i++) {
		cin >> style[i] >> upper[i];
	}

	vector<int> list(M);
	for (int i = 0; i < M; i++) cin >> list[i];

	int idx;
	for (int i = 0; i < M; i++) {
		idx = lower_bound(upper.begin(), upper.end(), list[i]) - upper.begin();
		cout << style[idx] << '\n';
	}

	return 0;
}