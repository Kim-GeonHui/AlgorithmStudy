#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int M;
	char tempChar;
	int tempNum;
	int min, max;
	multiset<int> numberSet;

	for (int i = 0; i < T; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> tempChar >> tempNum;
			if (tempChar == 'I') numberSet.insert(tempNum);
			else if (tempChar == 'D') {
				if (numberSet.size() == 0) continue;

				if (tempNum == 1) {
					auto it = numberSet.end();
					it--;
					numberSet.erase(it);
				}
				else if (tempNum == -1)
					numberSet.erase(numberSet.begin());
			}
		}

		if (numberSet.size() == 0) cout << "EMPTY" << '\n';
		else {
			min = *numberSet.begin();
			auto it = numberSet.end();
			it--;
			max = *it;
			cout << max << ' ' << min << '\n';
		}

		numberSet.clear();
	}

	return 0;
}