#include <stdio.h>
#include <iostream>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	queue<int> que;

	for (int i = 1; i < N + 1; i++) {
		que.push(i);
	}

	int tempNumber;

	while (que.size() != 1) {
		que.pop();
		tempNumber = que.front();
		que.pop();
		que.push(tempNumber);
	}

	cout << que.front();

	return 0;
}