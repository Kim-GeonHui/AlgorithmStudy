#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> numSet;

	int N;
	cin >> N;

	int tempNum;
	for (int i = 0; i < N; i++) {
		cin >> tempNum;
		numSet.insert(tempNum);
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tempNum;
			if (tempNum > *numSet.begin()) {
				numSet.erase(*numSet.begin());
				numSet.insert(tempNum);
			}
		}
	}

	cout << *numSet.begin() << '\n';

	return 0;
}