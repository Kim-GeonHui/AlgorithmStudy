#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int N, M;
vector<int> tree;

bool solve(int target) {
	long long answer = 0;
	for (int i = 0; i < N; i++) answer += max(0, tree[i] - target);
	return answer >= M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	tree.assign(N, 0);
	for (int i = 0; i < N; i++) cin >> tree[i];
	sort(tree.begin(), tree.end());

	int front, end, mid;
	front = 1;
	end = tree[N - 1];
	mid = (front + end) / 2;

	while (front < end) {
		if (solve(mid)) front = mid + 1;
		else end = mid;
		mid = (front + end) / 2;
	}

	cout << end - 1;
	return 0;
}