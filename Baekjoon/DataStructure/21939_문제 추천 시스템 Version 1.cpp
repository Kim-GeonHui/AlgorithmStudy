#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int tempNum1, tempNum2;
	string str;
	cin >> N;

	multiset<pair<int, int>> numSet;
	map<int, int> numMap;
	for (int i = 0; i < N; i++) {
		cin >> tempNum1 >> tempNum2;
		numSet.insert({ tempNum2, tempNum1 });
		numMap.insert({ tempNum1, tempNum2 });
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "add") {
			cin >> tempNum1 >> tempNum2;
			numSet.insert({ tempNum2, tempNum1 });
			numMap.insert({ tempNum1, tempNum2 });
		}
		else if (str == "recommend") {
			cin >> tempNum1;

			if (tempNum1 == 1) {
				auto it = numSet.rbegin();
				cout << it->second << '\n';
			}
			else if (tempNum1 == -1) {
				auto it = numSet.begin();
				cout << it->second << '\n';
			}
		}
		else if (str == "solved") {
			cin >> tempNum1;
			tempNum2 = numMap[tempNum1];
			numSet.erase({ tempNum2, tempNum1 });
		}
	}

	return 0;
}