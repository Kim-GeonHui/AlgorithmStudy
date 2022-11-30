#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> queue;

	int N;
	cin >> N;
	
	int tempNum;
	for (int i = 0; i < N; i++) {
		cin >> tempNum;

		if (tempNum == 0) {
			if (queue.size() == 0) cout << 0 << '\n';
			else {
				cout << queue.top() << '\n';
				queue.pop();
			}
		}
		else queue.push(tempNum);
	}

	return 0;
}