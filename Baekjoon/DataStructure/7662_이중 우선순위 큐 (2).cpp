#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, k, tempNum;
	char command;
	map<pair<int, int>, bool> validMap;
	priority_queue<pair<int, int>> queue1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue2;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> command >> tempNum;

			if (command == 'I') {
				queue1.push({ tempNum, j });
				queue2.push({ tempNum, j });
				validMap[{tempNum, j}] = true;
			}
			else if (command == 'D') {
				if (tempNum == 1) {
					while (!queue1.empty()) {
						if (validMap[{queue1.top().first, queue1.top().second}] == false) queue1.pop();
						else break;
					}
					if (queue1.empty()) continue;
					validMap[{queue1.top().first, queue1.top().second}] = false;
					queue1.pop();
				}
				else if (tempNum == -1) {
					while (!queue2.empty()) {
						if (validMap[{queue2.top().first, queue2.top().second}] == false) queue2.pop();
						else break;
					}
					if (queue2.empty()) continue;
					validMap[{queue2.top().first, queue2.top().second}] = false;
					queue2.pop();
				}
			}
		}

		while (!queue1.empty()) {
			if (validMap[{queue1.top().first, queue1.top().second}] == false) queue1.pop();
			else break;
		}
		while (!queue2.empty()) {
			if (validMap[{queue2.top().first, queue2.top().second}] == false) queue2.pop();
			else break;
		}

		if (queue1.empty()) cout << "EMPTY" << '\n';
		else cout << queue1.top().first << ' ' << queue2.top().first << '\n';

		while (!queue1.empty()) queue1.pop();
		while (!queue2.empty()) queue2.pop();
		validMap.clear();
	}

	return 0;
}