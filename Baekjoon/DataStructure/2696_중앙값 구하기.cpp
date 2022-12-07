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

	multiset<int> numSet;

	int T, M;
	int count;
	int tempNum;
	vector<int> answerArr;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M;

		cin >> tempNum;
		numSet.insert(tempNum);
		answerArr.push_back(tempNum);

		for (int j = 1; j < M; j++) {
			cin >> tempNum;
			numSet.insert(tempNum);
			if (j % 2 == 0) {
				auto it = numSet.begin();
				for (int k = 0; k < j / 2; k++) it++;
				answerArr.push_back(*it);
			}
		}

		cout << answerArr.size();
		for (int j = 0; j < answerArr.size(); j++) {
			if (j % 10 == 0) cout << '\n';
			cout << answerArr[j] << ' ';
		}
		cout << '\n';

		numSet.clear();
		answerArr.clear();
	}

	return 0;
}