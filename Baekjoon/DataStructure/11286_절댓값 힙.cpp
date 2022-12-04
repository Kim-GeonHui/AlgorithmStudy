#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	
	int tempNum;
	for (int i = 0; i < N; i++) {
		cin >> tempNum;
		if (tempNum == 0) {
			if (queue.empty()) cout << 0 << '\n';
			else {
				cout << queue.top().second << '\n';
				queue.pop();
			}
		}
		else 
			queue.push({ abs(tempNum), tempNum });
	}

	return 0;
}